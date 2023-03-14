# Meson Example Project

This project is intended to show the feature gap in using `--backend vs` wherein the generated Visual Studio project settings for executable targets do not include updating the `PATH` environment variable for local runtime dependencies (e.g., those supplied by the meson project's subproject(s)).  The `PATH` is updated for when `meson ...` commands are run, however, so the understanding that the Windows environment requires libraries to be visible on the `PATH` does appear to be supported by meson (it just is not conveyed fully to the generated project files).

## Requirements

* Meson >= 1.0
* Windows host OS (tested on 11 21H1)
* Visual Studio >= 2017 (tested on 2022)

## Issue Reproduction Steps

1. Configure meson: `meson setup builddir --backend vs`
2. Open the `builddir/Meson Example Project.sln` in Visual Studio
3. In the Solution Explorer, right-click the `main` project and press _Debug_ -> _Start new instance_.

A System Error dialog will be presented:

```
The code execution cannot proceed because `example.dll` was not found.  Reinstalling the program may fix the problem.
```

One can edit the `main` project's _Properties_, _Debugging_, and modify the _Environment_ to fix this issue.  The fix requires prepending the `PATH` variable with the full path to `builddir/subprojects/libexample`.

Alternatively, one can (at the command line):

```
meson compile -C builddir
meson test -C builddir
```

The executable will run without error because as shown at the top of the `testlog.txt`, the `PATH` included the location for `libexample`.
