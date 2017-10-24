/*Myron Pow, Dave Harden, CS2C, 3/9/2016
a9_1
Maximal flow
finds the maximal flow of a weighted graph
*/

#include <iostream>
#include <string>
using namespace std;
#include "FHflowGraph.h"

// --------------- main ---------------
int main()
{
   int finalFlow;

   // build graph
   FHflowGraph<string, int> myG;

   myG.addEdge("s", "a", 3); myG.addEdge("s", "b", 2);
   myG.addEdge("a", "b", 1); myG.addEdge("a", "c", 3); myG.addEdge("a", "d", 4);
   myG.addEdge("b", "d", 2);
   myG.addEdge("c", "t", 2);
   myG.addEdge("d", "t", 3);

   // show the original flow graph
   myG.showResAdjTable();
   myG.showFlowAdjTable();

   myG.setStartVert("s");
   myG.setEndVert("t");
   finalFlow = myG.findMaxFlow();

   cout << "Final flow: " << finalFlow << endl;

   myG.showResAdjTable();
   myG.showFlowAdjTable();

   cout << endl << endl << endl;
   cout << "FIG 9.39, pg 407" << endl << endl;
   //FIG 9.39, pg 407
    FHflowGraph<string, int> GG;

   GG.addEdge("s", "a", 4); GG.addEdge("s", "b", 2);
   GG.addEdge("a", "b", 1); GG.addEdge("a", "c", 2); GG.addEdge("a", "d", 4);
   GG.addEdge("b", "d", 2);
   GG.addEdge("c", "t", 3);
   GG.addEdge("d", "t", 3);

   // show the original flow graph
   GG.showResAdjTable();
   GG.showFlowAdjTable();

   GG.setStartVert("s");
   GG.setEndVert("t");
   finalFlow = GG.findMaxFlow();

   cout << "Final flow: " << finalFlow << endl;

   GG.showResAdjTable();
   GG.showFlowAdjTable();

   return 0;
}

/*RUN
------Res Adj Tbl----
Res List for s: a(3) b(2)
Res List for a: s(0) b(1) c(3) d(4)
Res List for b: s(0) a(0) d(2)
Res List for c: a(0) t(2)
Res List for d: a(0) b(0) t(3)
Res List for t: c(0) d(0)

-----Flow Adj Tbl-----
Flow Adj List for s: a(0) b(0)
Flow Adj List for a: b(0) c(0) d(0)
Flow Adj List for b: d(0)
Flow Adj List for c: t(0)
Flow Adj List for d: t(0)
Flow Adj List for t:

Final flow: 5
------Res Adj Tbl----
Res List for s: a(0) b(0)
Res List for a: s(0) b(1) c(1) d(3)
Res List for b: s(0) a(0) d(0)
Res List for c: a(0) t(0)
Res List for d: a(0) b(0) t(0)
Res List for t: c(0) d(0)

-----Flow Adj Tbl-----
Flow Adj List for s: a(3) b(2)
Flow Adj List for a: b(0) c(2) d(1)
Flow Adj List for b: d(2)
Flow Adj List for c: t(2)
Flow Adj List for d: t(3)
Flow Adj List for t:




FIG 9.39, pg 407

------Res Adj Tbl----
Res List for s: a(4) b(2)
Res List for a: s(0) b(1) c(2) d(4)
Res List for b: s(0) a(0) d(2)
Res List for c: a(0) t(3)
Res List for d: a(0) b(0) t(3)
Res List for t: c(0) d(0)

-----Flow Adj Tbl-----
Flow Adj List for s: a(0) b(0)
Flow Adj List for a: b(0) c(0) d(0)
Flow Adj List for b: d(0)
Flow Adj List for c: t(0)
Flow Adj List for d: t(0)
Flow Adj List for t:

Final flow: 5
------Res Adj Tbl----
Res List for s: a(1) b(0)
Res List for a: s(0) b(1) c(0) d(3)
Res List for b: s(0) a(0) d(0)
Res List for c: a(0) t(1)
Res List for d: a(0) b(0) t(0)
Res List for t: c(0) d(0)

-----Flow Adj Tbl-----
Flow Adj List for s: a(3) b(2)
Flow Adj List for a: b(0) c(2) d(1)
Flow Adj List for b: d(2)
Flow Adj List for c: t(2)
Flow Adj List for d: t(3)
Flow Adj List for t:

Press any key to continue . . .
*/