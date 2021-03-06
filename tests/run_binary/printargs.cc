// Copyright 2019 The Bazel Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* out_path = getenv("OUT");
  if (!out_path || !*out_path) {
    fprintf(stderr, "ERROR(" __FILE__ ":%d): envvar OUT is undefined\n",
            __LINE__);
    return 1;
  }
  FILE* f = fopen(out_path, "wt");
  if (!f) {
    fprintf(stderr, "ERROR(" __FILE__ ":%d): could not open output file '%s'\n",
            __LINE__, out_path);
    return 1;
  }
  for (int i = 1; i < argc; ++i) {
    fprintf(f, "arg%d=(%s)\n", i, argv[i]);
  }
  fclose(f);
  return 0;
}
