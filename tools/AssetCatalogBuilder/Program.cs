using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;
using CommandLine;
using CommandLine.Text;

namespace AssetCatalogBuilder
{
    class Options
    {
        public Options() { _TargetDevices = new HashSet<string>(); }

        [ParserState]
        public IParserState LastParserState { get; set; }

        [Option("output-format", HelpText = "Ignored")]
        public String OutputFormat { get; set; }

        [Option("export-dependency-info", HelpText = "Ignored")]
        public String DependecyInfoFile { get; set; }

        [Option("output-partial-info-plist", HelpText = "Ignored")]
        public String PartialInfoPlistFile { get; set; }

        [Option("platform", HelpText = "Ignored")]
        public String Platform { get; set; }

        [Option("minimum-deployment-target", HelpText = "Ignored")]
        public float MinDeploymentTarget { get; set; }

        [Option("app-icon", HelpText = "Ignored")]
        public String AppIcon { get; set; }

        [Option("launch-image", HelpText = "Ignored")]
        public String LaunchImage { get; set; }

        [Option("write", HelpText = "Ignored")]
        public String WritePath { get; set; }

        [Option("notices", DefaultValue = false)]
        public bool Notices { get; set; }

        [Option("warnings", DefaultValue = false)]
        public bool Warnings { get; set; }

        [Option("errors", DefaultValue = true)]
        public bool Errors { get; set; }

        [Option("target-device", HelpText = "[iphone|ipad]")]
        public String TargetDevices { get { return String.Join(" ", _TargetDevices); } set { _TargetDevices.Add(value); } }
        public HashSet<String> TargetDeviceSet { get { return _TargetDevices; } }
        HashSet<String> _TargetDevices;

        [Option("compile", Required = true, HelpText = "Compiled output path")]
        public String CompilePath { get; set; }

        [ValueOption(0)]
        public String AssetCatalog { get; set; }

        [HelpOption]
        public string GetUsage()
        {
            var help = new HelpText { AddDashesToOption = true };
            if (this.LastParserState != null && this.LastParserState.Errors.Any())
            {
                var errors = help.RenderParsingErrorsText(this, 2); // indent with two spaces
                if (!string.IsNullOrEmpty(errors))
                {
                    help.AddPreOptionsLine("ERROR(S):");
                    help.AddPreOptionsLine(errors);
                }
            }

            help.AddPreOptionsLine("Usage: acbuilder [OPTIONS] assetcatalog");
            help.AddOptions(this);

            return help;
        }
    }

    class Program
    {
        static Options options = new Options();
        static SimpleLogger logger = new SimpleLogger(LogSeverity.Error);

        static void processSetImages(String imageSetDir, object[] imageObjects)
        {
            HashSet<String> outputNames = new HashSet<String>();
            foreach (var obj in imageObjects)
            {
                try
                {
                    Dictionary<String, object> dict = obj as Dictionary<String, object>;
                    Dictionary<String, String> imageDesc = dict.ToDictionary(k => k.Key, k => k.Value.ToString());

                    String filename;
                    if (!imageDesc.TryGetValue("filename", out filename))
                    {
                        logger.Info("Skipping entry with missing filename in {0}.", Path.GetFileName(imageSetDir));
                        continue;
                    }

                    String filePath = Path.Combine(imageSetDir, filename);
                    if (!File.Exists(filePath))
                    {
                        logger.Info("Skipping {0} in {1} because the specified file does not exist.", filename, Path.GetFileName(imageSetDir));
                        continue;
                    }

                    String scale;
                    if (!imageDesc.TryGetValue("scale", out scale) || scale == "1x")
                        scale = System.String.Empty;
                    else
                        scale = "@" + scale;

                    String idiom;
                    if (!imageDesc.TryGetValue("idiom", out idiom) || idiom == "universal")
                    {
                        idiom = System.String.Empty;
                    }
                    else if (!options.TargetDeviceSet.Contains(idiom))
                    {
                        logger.Info("Skipping {0} in {1} because its idiom does not match any of the target devices.", filename, Path.GetFileName(imageSetDir));
                        continue;
                    }

                    // Check for name collisions before copying file
                    String outputName = Path.GetFileNameWithoutExtension(imageSetDir) + scale + idiom + Path.GetExtension(filename);
                    if (outputNames.Add(outputName))
                    {
                        String outputPath = Path.Combine(options.CompilePath, outputName);
                        File.Copy(filePath, outputPath);
                    }
                    else
                    {
                        logger.Info("Skipping image in {0} with duplicate output name: {1}", Path.GetFileName(imageSetDir), outputName);
                        continue;
                    }
                }
                catch (System.Exception) { }
            }
        }

        static void processImageSets(Dictionary<String, String> catalogDict)
        {
            foreach(var entry in catalogDict)
            {
                // Get set image descriptions
                String contentsFile = Path.Combine(entry.Value, "Contents.json");
                try
                {
                    string jsonString = File.ReadAllText(contentsFile);
                    var serializer = new JavaScriptSerializer();
                    var result = serializer.DeserializeObject(jsonString);
                    var jsonObjects = result as Dictionary<String, object>;
                    object[] images = jsonObjects["images"] as object[];
                    processSetImages(entry.Value, images);
                }
                catch (System.Exception)
                {
                    logger.Error("Error processing {0} set contents.", contentsFile);
                }
            }
        }

        static void getCatalogSets(String catalogDir, Dictionary<String, String> catalogDict)
        {
            try
            {
                foreach (string d in Directory.GetDirectories(catalogDir))
                {
                    // Consider the directory "extension"
                    String catalogExt = Path.GetExtension(d);
                    if (catalogExt.Length == 0)
                    {
                        getCatalogSets(d, catalogDict);
                    }
                    else if (catalogExt == ".imageset")
                    {
                        // In case of key collisions, only care about the first value seen
                        try
                        {
                            catalogDict.Add(Path.GetFileName(d), d);
                        }
                        catch (ArgumentException)
                        {
                            logger.Info("Skipping {0} image set with duplicate name.", d);
                        }
                    }
                    else
                    {
                        logger.Info("Skipping unrecognized set directory: {0}", d);
                    }
                }
            }
            catch (System.Exception)
            {
                logger.Error("Unable to get directory listing for {0}.", catalogDir);
            }
        }

        static void Main(string[] args)
        {
            // Parse command-line options. Parser will exit on failure.
            CommandLine.Parser.Default.ParseArgumentsStrict(args, options);

            // Set logger severity
            if (options.Notices)
                logger.Severity = LogSeverity.Info;
            else if (options.Warnings)
                logger.Severity = LogSeverity.Warning;

            // Validate input catalog
            if (String.IsNullOrEmpty(options.AssetCatalog))
                logger.Error("No input asset catalog specified.");

            // Validate output directory
            if (!Directory.Exists(options.CompilePath))
                logger.Error("Specified output directory does not exist.");

            // Get all image sets in the asset catalog
            var catalogDict = new Dictionary<String, String>();
            getCatalogSets(options.AssetCatalog, catalogDict);

            // Process image sets
            processImageSets(catalogDict);
        }
    }
}
