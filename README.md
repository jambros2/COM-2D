# Center of Mass of 2D Shapes #

This program calculate the center of mass of a combination of 2D shapes assuming constant
thickness and density. The combination may be any combination of semicircles, circles, 
rectangles, and triangles. Additionally, these shapes may be represented as a part of the 
solid or a hole within the solid. Defined parts of the solid must only touch on their edges,
and holes must be completely bounded by the combination of the solids. The center of mass for
the combination is computed by using standard equations for each individual shape and using the
area of the shapes in place of their mass when calculating the center of mass of their 
combination. 

Because this code was written purely as a code sample, error checking for the requirements of 
the shapes is not done. Additionally, the input file defining the shapes is hard-coded to be
`test_cases/shape.csv`, as I chose not to parse from the command line given the scope of this
sample. Additionally, all shapes are locked in a given orientation, as I have left the 
rotation of the shapes and the mirroring of them to be a future exercise.

As a code sample, this demonstrates:  

  - Use of classes
  - Use of templating and polymorphism
  - I/O operations
  - Use of makefiles
  - Doxygen for documentation
  - GitHub for version control
  - Use of Markdown and READMEs for out-of-source documentation

For any questions, concerns, or comments, please contact me at daniel-ambrose@outlook.com

## Build Instructions ##

For building within the root directory, simply run `make all` at the bash prompt.
```
make all
```

### Cleaning ###

The build tree may be clean by running: 
```
make clean
```

## Execution ##

The program may be ran from the root directory of this repo by executing
```
./bin/com
```
