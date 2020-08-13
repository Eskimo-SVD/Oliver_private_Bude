#!/usr/bin/wolfram -script
data = WolframAlpha["longest tunnels", "ComputableData", TimeConstraint->120]
lengths = data /. {a_, b_, c_, d_} -> {c} // Flatten
labels = data /. {a_, b_, c_, d_} -> {b} // Flatten
chart = BarChart[lengths, ChartLabels -> labels, BarOrigin -> Left]
Export["tunnels.jpg", chart, ImageSize -> {800, 600}]
