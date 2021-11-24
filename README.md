To reproduce (on Windows using VS Community):

1. `cmake -E make_directory build`
1. `cmake -E chdir build cmake ..`
1. `cmake --build build --config Debug`
1. Uncomment the last line with `add_dependencies` for convenience
1. `cmake --build build --config Debug`
1. Observe the various outputs that _do not_ contain a single string arg with a semicolon-delimited list of paths.
