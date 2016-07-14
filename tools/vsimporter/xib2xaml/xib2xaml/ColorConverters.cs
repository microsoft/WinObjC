// ******************************************************************************
// 
//  Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// 
//  This code is licensed under the MIT License (MIT).
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// 
// ******************************************************************************

using System;

namespace Xib2Xaml
{
    internal class ColorConverters
    {
        public static double[] xyzd65 = {0.9505, 1.0, 1.0890};

        public static byte[] LabToRGB(double l, double a, double b)
        {
            return XYZtoRGB(LabtoXYZ(l, a, b));
        }

        public static double[] LabtoXYZ(double l, double a, double b)
        {
            var delta = 6.0/29.0;

            var fy = (l + 16)/116.0;
            var fx = fy + a/500.0;
            var fz = fy - b/200.0;

            double[] xyz =
            {
                fx > delta ? xyzd65[0]*(fx*fx*fx) : (fx - 16.0/116.0)*3*(delta*delta)*xyzd65[0],
                fy > delta ? xyzd65[1]*(fy*fy*fy) : (fy - 16.0/116.0)*3*(delta*delta)*xyzd65[1],
                fz > delta ? xyzd65[2]*(fz*fz*fz) : (fz - 16.0/116.0)*3*(delta*delta)*xyzd65[2]
            };

            return xyz;
        }

        public static byte[] XYZtoRGB(double[] xyz)
        {
            var x = xyz[0];
            var y = xyz[1];
            var z = xyz[2];

            if (x > 0.9505)
                x = 0.9505;
            if (x < 0)
                x = 0;
            if (y > 1)
                y = 1;
            if (y < 0)
                y = 0;
            if (z > 1.089)
                z = 1.089;
            if (z < 0)
                z = 0;

            var Clinear = new double[3];
            Clinear[0] = x*3.2410 - y*1.5374 - z*0.4986; // red
            Clinear[1] = -x*0.9692 + y*1.8760 - z*0.0416; // green
            Clinear[2] = x*0.0556 - y*0.2040 + z*1.0570; // blue

            for (var i = 0; i < 3; i++)
            {
                Clinear[i] = Clinear[i] <= 0.0031308
                    ? 12.92*Clinear[i]
                    : (
                        1 + 0.055)*Math.Pow(Clinear[i], 1.0/2.4) - 0.055;
            }

            byte[] rgb =
            {
                Convert.ToByte(double.Parse(string.Format("{0:0.00}",
                    Clinear[0]*255.0))),
                Convert.ToByte(double.Parse(string.Format("{0:0.00}",
                    Clinear[1]*255.0))),
                Convert.ToByte(double.Parse(string.Format("{0:0.00}",
                    Clinear[2]*255.0)))
            };

            return rgb;
        }

        public static byte[] CMYKtoRGB(double c, double m, double y, double k)
        {
            var red = Convert.ToByte((1 - c)*(1 - k)*255.0);
            var green = Convert.ToByte((1 - m)*(1 - k)*255.0);
            var blue = Convert.ToByte((1 - y)*(1 - k)*255.0);

            return new[] {red, green, blue};
        }
    }
}