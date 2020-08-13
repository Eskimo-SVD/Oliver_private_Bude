#!/usr/bin/wolfram -script
(* raw = Import["/var/log/temp.csv"]; *)
raw = Import["temp.csv"];
last = raw[[-1,1]];         (* Zeitpunkt der letzten Messung *)
start = DatePlus[last, {-1, "Day"}];       (* ein Tag vorher *)
startstr = DateString[start, {"Year", "-", "Month", "-", "Day", 
  "T", "Hour", ":", "Minute"}];          (* als Zeichenkette *)
rawlast24h = Select[raw, Order[#[[1]], startstr] == -1 & ];
trans[x_List] :=  {x[[1]], ToExpression[StringDrop[x[[2]], 2]] / 1000};
data = Map[trans, rawlast24h];
graphic = DateListPlot[data, Joined->True];
Export["test.png", graphic, ImageSize -> 1100]
