/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Note that, with the call to gvParseArgs(), this application assumes that
 * a known layout algorithm is going to be specified. This can be done either
 * using argv[0] or requiring the user to run this code with a -K flag specifying
 * which layout to use. In the former case, after this program has been built as
 * 'demo', you will need to rename it as one of the installed layout engines such
 * as dot, neato, sfdp, etc.
 */
#include <gvc.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
  Agraph_t *g;
  Agnode_t *n, *m;
  Agedge_t *e;
  GVC_t *gvc;
  FILE *fp;
#define MAX_LINE_SIZE (3873 + 1 + 1) // By inspection of ps_out.txt. This 3873 is the max number of chars on a single line.
  char line[MAX_LINE_SIZE];
  int pid, ppid;
  char cmd[MAX_LINE_SIZE];
  int n_inputs;
  char *s;
  int n;

#define NUM_PS_COLUMNS 15 // By inspection of ps_out.txt.

  fp = fopen("ps_out.txt", "r");
  // TODO check return value.
  assert(fp != NULL);

  s = fgets(line, MAX_LINE_SIZE, fp); // Consume the first line.
  // TODO check return value.
  assert(s != NULL);

  while ( ( n_inputs = fscanf(fp, "%*d %d %d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s\n", &pid, &ppid, cmd) ) >= 0) {

    if (n_inputs == 0) {
      s = fgets(line, MAX_LINE_SIZE, fp);
      // TODO check return value.
      assert(s != NULL);
    } else {
      printf("next line = pid %d. ppid %d. cmd %s.\n", pid, ppid, cmd);
    }

  }

  // TODO check return value.

  // TODO check return value.

  n = fclose(fp);
  // TODO check return value.
  assert(n == 0);

  /* set up a graphviz context */
  gvc = gvContext();

  /* parse command line args - minimally argv[0] sets layout engine */
  gvParseArgs(gvc, argc, argv);

  /* Create a simple digraph */

  /*
   ******* From the man cgraph page.

   agopen
    creates a new graph with the  given  name

    Graph kinds
      are  Agdirected,  Agundirected, Agstrictdirected, and Agstric-
      tundirected.

    The  final argument
      points to a discpline structure
      to tailor I/O, memory allocation, and  ID  allocation.
        NULL
          default discipline AgDefault-Disc
  */
  g = agopen("g", Agdirected, 0);
  n = agnode(g, "n", 1);
  m = agnode(g, "m", 1);
  e = agedge(g, n, m, 0, 1);

  /* Set an attribute - in this case one that affects the visible rendering */
  agsafeset(n, "color", "red", "");

  /* Compute a layout using layout engine from command line args */
  gvLayoutJobs(gvc, g);

  /* Write the graph according to -T and -o options */
  gvRenderJobs(gvc, g);

  /* Free layout data */
  gvFreeLayout(gvc, g);

  /* Free graph structures */
  agclose(g);

  /* close output file, free context, and return number of errors */
  return (gvFreeContext(gvc));
}