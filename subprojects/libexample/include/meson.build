install_headers(['api.h', 'example.h'])

# Generate the config.h from the cdata defined at the project root.
configure_file(output: 'config.h', configuration: cdata)

lib_example_inc = include_directories('.')
