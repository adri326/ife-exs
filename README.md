# ife-ex

(Very simple) exercises in C.
My coding style heavily deviates from the one we were suggested.
This is due to theirs being outdated, poorly sourced/justified or going against my own standards.

## Installation

Clone this repository:

```sh
git clone https://github.com/adri326/ife-exercises
cd ife-ex
```

Then build the project:

```sh
mkdir build && cd build
cmake ..
make
```

### Building notes

Since there are a lot of projects to build at once, you might want to take advantage of multi-threading the process with `make -j`.

To disable colors, run cmake with the `-DNO_COLOR=true` argument. If you wish to revert this back, run cmake with `-DNO_COLOR=false`.
