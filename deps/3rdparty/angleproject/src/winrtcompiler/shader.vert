precision mediump float;
attribute vec3 a_position;
attribute vec3 a_color;
varying vec4 v_color;
uniform mat4 u_mvp;
void main(void)
{
    gl_Position = u_mvp * vec4(a_position, 1);
    v_color = vec4(a_color, 1);
}