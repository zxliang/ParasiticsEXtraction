# PEX project parser: A parser for reading .DEF and .SPEF file
======================

Author: 
1. Zhaoxin Liang @ University of Minnesota - Twin Cities, VLSI - EDA group. (current author, zxliang@umn.edu)
2. Kishor Kunal (original author, kunal001@umn.edu)

Description: 
1. This parser reads interconnect information from .DEF file and matches the parasitic RC information from .SPEF file and organizes the information into training examples into nets.csv file. 

Usage:
1. .DEF file and .SPEF file should be the same directory
2. Compilation:
   - make
   - ./parser \*.def \*.spef \*output_file_name


Version: 
2.0 (Previous to Sep. 01, 2018)

License:
(N/A) by Zhaoxin Liang

----------------------
