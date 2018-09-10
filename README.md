# PEX project parser: A parser for .DEF and .SPEF file

## Description:
1. This parser reads interconnect information from .DEF file and matches the parasitic RC information from .SPEF file and organizes the information into training examples into nets.csv file. 

## Usage:
1. .DEF file and .SPEF file should be the same directory
2. Compilation:
```
   make
   ./parser \*.def \*.spef \*output_file_name
```

## Change Log:
1. 09/10/2018: Input file wrapper finished.

## Author: 
1. Zhaoxin Liang @ University of Minnesota - Twin Cities, [VLSI - EDA group](http://people.ece.umn.edu/users/sachin/). (current author, zxliang@umn.edu)
2. Kishor Kunal. (original author, kunal001@umn.edu)

## Version: 
2.0 (Previous to Sep. 01, 2018)

## License:
License TBD
Copyright &copy; 2018 [Zhaoxin Liang](https://github.com/zxliang)

----------------------

