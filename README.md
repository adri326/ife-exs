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

## If you are looking for...

Here is a list of the exercises that illustrate concepts of the C language.

* Colors: `12.15`, `12.14`
* Pointers: `7.6`, `10.1`, **`10.2`**, 12-series
* Arrays: `10.1`, `12.3`, `12.5`, `12.9`
* Structures: *none, yet*
* Dynamic memory allocation: `11.6`, `12.9`, `12.12`
* `fgets` and `sscanf`: `7.2`, `9.6`, `12.12`
* Strings: 13-series
