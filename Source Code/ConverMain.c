#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char** argv) {
  // Check that a file name was passed as an argument
  if (argc < 2) {
    printf("Error: no file name provided.\n");
    return 1;
  }

  // Open the OBJ file
  FILE* file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: unable to open file '%s'.\n", argv[1]);
    return 1;
  }

  // Read the file line by line
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    // Check if this line defines a vertex
    if (line[0] == 'v' && line[1] == ' ') {
      // Parse the line to extract the x, y, and z coordinates of the vertex
      float x, y, z;
      sscanf(line, "v %f %f %f", &x, &y, &z);

      // Print the vertex coordinates to the console
      printf("Vertex: (%f, %f, %f)\n", x, y, z);
    }
  }

  // Close the file and return success
  fclose(file);
  return 0;
}
