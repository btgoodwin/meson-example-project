project('Meson Example Project', 'cpp',
  meson_version: '>=1.0')

libexample_dep = subproject('libexample').get_variable('libexample_dep')

subdir('src')
main = executable('main', app_src, dependencies: libexample_dep, install: true)

subdir('tests')
