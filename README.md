# PIC

This project in an ecosystem for creating projects on the PIC18 and PIC32 platforms. Common and targeted libraries to interface the various peripherals are created for the two architectures. The general structure is to configure the IncSystemDefs files for a given chip and implementation. This file acts as a hardware abstraction layer (HAL), creating friendly/common names that the libraries are built around and assigning them to specific pins. Additionally, blocks of defines can be enabled to implement specific peripherals. 

Once the HAL is configured in the appropriate IncSystemDefs file (PICDEFS.h or PICDEFS32.h), the library projects can then be used in the target project. By including the HAL file and the resources from the various libraries the nitty gritty details of using the peripherals is taken care of. The peripheral libraries are the only other set of files that are architecture dependent. The other libraries provide a platform independent method of using various sensors, displays and mechanical output devices. Some of these libraries make use of the peripheral libraries but it should be smart enough to figure out which implementation is active. 

Lastly, I've included a few projects that I've developed. These range from development projects I used to create the libraries to some application projects that utilize the libraries to achieve various things. 
