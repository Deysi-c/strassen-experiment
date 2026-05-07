set terminal pngcairo size 800, 500 enhanced font 'Arial, 11'
set output 'data/grafica.png'

set title 'Strassen vs Estandar'
set xlabel 'Tamaño n'
set ylabel 'Tiempo mediano (ms)'
set logscale x 2
set logscale y
set format x "%g"
set grid
set key top left

plot 'data/results.txt' using 1:2 with linespoints pt 7 lc rgb 'blue' title 'Estandar O(n^3)', \
     'data/results.txt' using 1:3 with linespoints pt 5 dt 2 lc rgb 'red' title 'Strassen (base=64)'
