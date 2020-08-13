#!/usr/bin/wolfram -script
(* raw = Import["/var/log/temp.csv"]; *)
raw = Import["temp.csv"];
trans[x_List] :=  {x[[1]], ToExpression[StringDrop[x[[2]], 2]] / 1000};
data = Map[trans, raw];
graphic = DateListPlot[data, Joined->True];
Export["test.png", graphic, ImageSize -> 1100]
