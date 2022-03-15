#!/bin/bash

mode=$1
h=$2

rm -rf output/activity-$h/$mode
mkdir output/activity-$h/$mode

grammar='input/activity/grammar'
data='input/activity/activity.csv'
group='input/activity/k'

for k in {3..20..1};
do
    echo output/activity-$h/$mode/k$k
    rm -rf output/activity-$h/$mode/k$k
    mkdir output/activity-$h/$mode/k$k
    echo 'seed;training;test;validation;model' > output/activity-$h/$mode/k$k/res.csv

    echo 'Resolvendo fold ' $k
    for i in {1..3..3};
    do
        echo 'Resolvendo instância ' $i
        echo 'Resolvendo instância ' $((i + 1))
        echo 'Resolvendo instância ' $((i + 2))
        
        ./bin/Release/gpufjf $i         $grammar $data $group$k.dat $mode output/activity-$h/$mode/k$k/res.csv $h > output/activity-$h/$mode/k$k/$i.txt &
        ./bin/Release/gpufjf $((i + 1)) $grammar $data $group$k.dat $mode output/activity-$h/$mode/k$k/res.csv $h > output/activity-$h/$mode/k$k/$((i + 1)).txt &
        ./bin/Release/gpufjf $((i + 2)) $grammar $data $group$k.dat $mode output/activity-$h/$mode/k$k/res.csv $h > output/activity-$h/$mode/k$k/$((i + 2)).txt
    done
done
