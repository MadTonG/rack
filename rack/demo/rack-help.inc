Rack - a radar data processing program

--append  
  Append outputs instead of overwriting. Deprecated, see --store

--autoExec  <exec>
  Execute script automatically after each input. See --script

--checkType  
  Ensures ODIM types, for example after reading image data and setting attributes in command line std::strings.

--convert  
  Convert --select'ed data to scaling and markers set by --target

--dataOk, -�  <flag>
  Status of last select.

--debug  
  Set debugging mode

--delete  <selector>
  Deletes selected parts of h5 structure.

--dumpMap  <filter>,<filename>
  Dump variable map, filtered by keys, to std or file.

--encoding, -e  <type>,<gain>,<offset>,<undetect>,<nodata>,<rscale>,<nrays>,<nbins>
  Sets encodings parameters for polar and Cartesian products, including composites.

--exec  
  Execute a script.

--execFile  <filename>
  Execute commands from a file.

--expandVariables  
  Toggle variable expansion on/off

--format  <format>
  Set format for data dumps (see --sample or --outputFile)

--formatFile  <filename>
  Read format for metadata dump from a file

--formatOut  <filename>
  Dumps the formatted std::string to a file or stdout.

--geoTiffTile  <tilewidth>,<tileheight>
  GeoTIFF tile size

--help, -h  <keyword>
  Dump help and exit.

--helpExample  <keyword>
  Dump example of use and exit.

--histogram  <count>,<min>,<max>
  Histogram

--image  
  Copies data to a separate image object. Encoding can be changed with --target .

--imageAlpha  
  Adds a transparency channel. Creates current image if nonexistent. See --target

--imageFlatten  <bgcolor>
  Removes a alpha (transparency) channel. Adds a new background of given color.

--imageOp  <operator>,<parameters>
  Run image operator. See --select and --help imageOps.

--inputFile, -i  <filename>
  Read h5, txt or png file

--inputPrefix  <path>
  Path prefix for input files.

--inputSelect  <value>
  Read ATTRIBUTES (1), DATA(2) or both (3).

--keep  <selector>
  Keeps a part of the current h5 structure, deletes the rest. Path and quantity are regexps.

--legendOut  <filename>
  Save palette as a legend to a SVG file.

--outputFile, -o  <filename>
  Output current data to .hdf5, .png, .txt, .mat file. See also: --image, --outputRawImages.

--outputPrefix  <path>
  Path prefix for output files.

--outputRawImages, -O  <filename>
  Output datasets to png files named filename[NN].ext.

--palette  <filename>
  Load and apply palette.

--paletteRefine  <count>
  Refine colors

--quantity, -Q  <quantity>
  Same as --select quantity.

--quantityConf  <quantity:type>,<gain>,<offset>,<undetect>,<nodata>,<zero>
  1) list quantities, 2) set default type for a quantity, 3) set default scaling for (quantity,type) pair

--renameODIM  <from,to>
  Rename path (future ext: attribute)

--sample  <iStep>,<jStep>,<iStart>,<jStart>,<iEnd>,<jEnd>,<commentChar>,<skipVoid>
  Sampling configuration. See --format and --outFile '*.dat'.

--script  <script>
  Define a script.

--select, -s  <selector>
  Data selection for the next operation.

--setODIM  <assignment>
  Set data properties (ODIM).

--status  
  Dump information on current images.

--store  <append>,<intermediate>
  Set how intermediate and final outputs are stored.

--target, -t  <type>,<gain>,<offset>,<undetect>,<nodata>,<rscale>,<nrays>,<nbins>
  Sets encodings parameters for polar and Cartesian products, including composites.

--undetectWeight  <weight>
  Set the relative weight of data values assigned 'undetect'.

--verbose, -v  <level>
  Set verbosity level

--verboseData  <level>
  Determines if also intermediate results (1) are saved. Replacing --aStore ?

--version  
  Displays software version and quits.

For help, type:
 --help andre
 --help cart
 --help formulae
 --help prod
