project('Example library', 'cpp',
  meson_version: '>=1.0')

# Setup config data for dll import/export from the lib.
cc = meson.get_compiler('cpp')
host_system = host_machine.system()
extra_args = []

cdata = configuration_data()
if get_option('default_library') != 'static'
  if host_system == 'windows'
    cdata.set('DLL_EXPORT', true)
    if cc.get_id() == 'msvc'
      cdata.set('EXAMPLE_LIB_EXPORT', '__declspec(dllexport)')
      cdata.set('EXAMPLE_LIB_IMPORT', '__declspec(dllimport)')
    else
      cdata.set('EXAMPLE_LIB_EXPORT', '__attribute__((visibility("default"))) __declspec(dllexport)')
      cdata.set('EXAMPLE_LIB_IMPORT', '__attribute__((visibility("default"))) __declspec(dllimport)')
      extra_args += ['-fvisibility=hidden']
    endif
  else
    cdata.set('EXAMPLE_LIB_EXPORT', '__attribute__((visibility("default")))')
    cdata.set('EXAMPLE_LIB_IMPORT', '__attribute__((visibility("default")))')
    extra_args += ['-fvisibility=hidden']
  endif
endif

subdir('include')
subdir('src')

cpp_args = [
  '-DEXAMPLE_LIB_COMPILATION',
]
common_ldflags = []

libexample = library('example', lib_example_src,
  include_directories: lib_example_inc,
  cpp_args: cpp_args,
  link_args: common_ldflags,
  install: true,
)

libexample_dep = declare_dependency(
  link_with: libexample,
  include_directories: lib_example_inc,
)
