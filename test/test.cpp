#include <catch2/catch_test_macros.hpp>
#include <iostream>
#define private public  // Make private members of Graph public for testing
#include "Graph.h"

using namespace std;



TEST_CASE("Test 1: Circular/Undirected", "[custom1]"){

    SECTION("Three vertices") {
        string input, expectedOutput, actualOutput;

        input = R"(6 5
a.com b.com
a.com c.com
b.com c.com
c.com b.com
c.com a.com
b.com a.com)";

        expectedOutput = R"(a.com 0.33
b.com 0.33
c.com 0.33
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }

    SECTION("Four vertices") {
        string input, expectedOutput, actualOutput;

        input = R"(10 5
a.com b.com
a.com c.com
b.com c.com
c.com b.com
c.com a.com
b.com a.com
c.com d.com
b.com d.com
d.com c.com
d.com b.com)";

        expectedOutput = R"(a.com 0.21
b.com 0.29
c.com 0.29
d.com 0.21
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }

    SECTION("Five vertices") {
        string input, expectedOutput, actualOutput;

        input = R"(14 5
a.com b.com
a.com c.com
b.com c.com
c.com b.com
c.com a.com
b.com a.com
c.com d.com
b.com d.com
d.com c.com
d.com b.com
c.com e.com
d.com e.com
e.com d.com
e.com c.com)";

        expectedOutput = R"(a.com 0.15
b.com 0.21
c.com 0.28
d.com 0.21
e.com 0.15
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }
}


TEST_CASE("Test 2: Convergence consistency - 50 power iterations", "[custom2]") {

    SECTION("Four vertices") {
        string input_1, input_2;

        input_1 = R"(10 )";

        input_2 = R"(a.com b.com
a.com c.com
b.com c.com
c.com b.com
c.com a.com
b.com a.com
c.com d.com
b.com d.com
d.com c.com
d.com b.com)";


        for (int powerIterations = 1; powerIterations <= 50; powerIterations++) {
            string input, actualOutput, expectedOutput;
            input = input_1 + to_string(powerIterations) + "\n" + input_2;

            Graph graph;
            graph.parseInput(graph, input);
            actualOutput = graph.getStringRepresentation();

            if (powerIterations == 1) {
                expectedOutput = R"(a.com 0.25
b.com 0.25
c.com 0.25
d.com 0.25
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations == 2) {
                expectedOutput = R"(a.com 0.17
b.com 0.33
c.com 0.33
d.com 0.17
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations == 3) {
                expectedOutput = R"(a.com 0.22
b.com 0.28
c.com 0.28
d.com 0.22
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations == 4) {
                expectedOutput = R"(a.com 0.19
b.com 0.31
c.com 0.31
d.com 0.19
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations == 5) {
                expectedOutput = R"(a.com 0.21
b.com 0.29
c.com 0.29
d.com 0.21
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations == 6) {
                expectedOutput = R"(a.com 0.19
b.com 0.31
c.com 0.31
d.com 0.19
)";
                REQUIRE(actualOutput == expectedOutput);
            }
            else if (powerIterations >= 7) {
                expectedOutput = R"(a.com 0.20
b.com 0.30
c.com 0.30
d.com 0.20
)";
                REQUIRE(actualOutput == expectedOutput);
            }
        }
    }
}

TEST_CASE("Test 3: High number of power iterations", "[custom3]") {

    SECTION("Four vertices - 10,000 power iterations") {
        string input, expectedOutput, actualOutput;

        input = R"(10 10000
a.com b.com
a.com c.com
b.com c.com
c.com b.com
c.com a.com
b.com a.com
c.com d.com
b.com d.com
d.com c.com
d.com b.com)";

        expectedOutput = R"(a.com 0.20
b.com 0.30
c.com 0.30
d.com 0.20
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }


}

TEST_CASE("Test 4: Disconnected graph", "[custom4]") {

    SECTION("Two disconnected clusters") {
        string input, expectedOutput, actualOutput;

        input = R"(10 5
a.com b.com
a.com c.com
a.com e.com
c.com e.com
e.com f.com
f.com a.com
w.com x.com
w.com y.com
y.com z.com
z.com w.com)";

        expectedOutput = R"(a.com 0.07
b.com 0.05
c.com 0.05
e.com 0.09
f.com 0.07
w.com 0.06
x.com 0.03
y.com 0.03
z.com 0.06
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }

    SECTION("Three disconnected clusters") {
        string input, expectedOutput, actualOutput;

        input = R"(15 5
a.com b.com
a.com c.com
a.com e.com
c.com e.com
e.com f.com
f.com a.com
w.com x.com
w.com y.com
y.com z.com
z.com w.com
l.com m.com
m.com n.com
n.com o.com
o.com m.com
m.com p.com)";

        expectedOutput = R"(a.com 0.05
b.com 0.03
c.com 0.03
e.com 0.06
f.com 0.05
l.com 0.00
m.com 0.07
n.com 0.02
o.com 0.04
p.com 0.02
w.com 0.04
x.com 0.02
y.com 0.02
z.com 0.04
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }
}


TEST_CASE("Test 5: Long chain/Power iteration chain test", "[custom5]") {

    SECTION("8 nodes") {
        string input, expectedOutput, actualOutput;

        input = R"(7 10
a.com b.com
b.com c.com
c.com d.com
d.com e.com
e.com f.com
f.com g.com
g.com h.com)";

        expectedOutput = R"(a.com 0.00
b.com 0.00
c.com 0.00
d.com 0.00
e.com 0.00
f.com 0.00
g.com 0.00
h.com 0.00
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }

    SECTION("18 nodes") {
        string input, expectedOutput, actualOutput;

        input = R"(17 10
a.com b.com
b.com c.com
c.com d.com
d.com e.com
e.com f.com
f.com g.com
g.com h.com
h.com i.com
i.com j.com
j.com k.com
k.com l.com
l.com m.com
m.com n.com
n.com o.com
o.com p.com
p.com q.com
q.com r.com)";

        expectedOutput = R"(a.com 0.00
b.com 0.00
c.com 0.00
d.com 0.00
e.com 0.00
f.com 0.00
g.com 0.00
h.com 0.00
i.com 0.00
j.com 0.06
k.com 0.06
l.com 0.06
m.com 0.06
n.com 0.06
o.com 0.06
p.com 0.06
q.com 0.06
r.com 0.06
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }
}


TEST_CASE("Test 6: Outdegree zero", "[custom6]") {

    SECTION("Cycle ") {
        string input, expectedOutput, actualOutput;

        input = R"(4 10
a.com b.com
b.com c.com
c.com a.com
c.com d.com)";

        expectedOutput = R"(a.com 0.03
b.com 0.03
c.com 0.03
d.com 0.03
)";

        Graph graph;

        graph.parseInput(graph, input);
        actualOutput = graph.getStringRepresentation();

        REQUIRE(actualOutput == expectedOutput);
    }
}