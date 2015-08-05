How to use the WinRT shader compiler:

- the usage for the program is:

winrtcompiler [-o=[file] -p=[platform] -a=[variable]] -v=[vertex_shader_1] ... -v=[vertex_shader_1] -f=[fragment_shader_1] ... -f=[fragment_shader_n]]
Where:  -o=[file] : output file\n"
        -a=[variable] : output to char array named [variable] in header file, omit for binary file\n");
        -p=[platform] : wp8 or winrt\n"
		-v=[vertex_shader_n] : vertex shader file
        -f=[fragment_shader_n] : fragment shader file

see winrtcompiler.bat for an example.