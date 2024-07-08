#!/usr/bin/gnuplot -c

set datafile separator ","
set grid
set key bottom right
set xrange [5.5:32.5]
set xtics 2.5
set ytics 2.5
set termoption lw 2

plot x 																										lc rgbcolor hsv2rgb(  0/360.0,0.0,0.5)	title "ideal",\
     "zoe_ze50_r110_one_phase.csv"							using ($2):($6)						with lines	lc rgbcolor hsv2rgb(  0/360.0,0.5,1.0)	title "Scheinstrom R110 1P",\
     "zoe_ze50_r110_one_phase.csv"							using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(  0/360.0,1.0,1.0)	title "Wirkstrom R110 1P",\
     "zoe_ze50_r110_three_phases.csv"						using ($2):($25)					with lines	lc rgbcolor hsv2rgb( 20/360.0,0.5,1.0)	title "Scheinstrom R110 3P",\
     "zoe_ze50_r110_three_phases.csv"						using ($2):($27/($48/sqrt(3))/3)	with lines	lc rgbcolor hsv2rgb( 20/360.0,1.0,1.0)	title "Wirkstrom R110 3P",\
     "zoe_ze50_r135_one_phase.csv" 							using ($2):($6)						with lines	lc rgbcolor hsv2rgb( 40/360.0,0.5,1.0)	title "Scheinstrom R135? 1P",\
     "zoe_ze50_r135_one_phase.csv"							using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb( 40/360.0,1.0,1.0)	title "Wirkstrom R135? 1P",\
     "zoe_ze50_r135_three_phases.csv"						using ($2):($25)					with lines	lc rgbcolor hsv2rgb( 60/360.0,0.5,1.0)	title "Scheinstrom R135 3P",\
     "zoe_ze50_r135_three_phases.csv"						using ($2):($27/($48/sqrt(3))/3)	with lines	lc rgbcolor hsv2rgb( 60/360.0,1.0,1.0)	title "Wirkstrom R135 3P",\
     "model_3_three_phases.csv" 							using ($2):($25)					with lines	lc rgbcolor hsv2rgb( 80/360.0,0.5,1.0)	title "Scheinstrom Model 3 3P",\
     "model_3_three_phases.csv"								using ($2):($27/($48/sqrt(3))/3)	with lines	lc rgbcolor hsv2rgb( 80/360.0,1.0,1.0)	title "Wirkstrom Model 3 3P",\
     "enyaq_iv_60_three_phases.csv"							using ($2):($25)					with lines	lc rgbcolor hsv2rgb(100/360.0,0.5,1.0)	title "Scheinstrom Enyaq 3P",\
     "enyaq_iv_60_three_phases.csv"							using ($2):($27/($48/sqrt(3))/3)	with lines	lc rgbcolor hsv2rgb(100/360.0,1.0,1.0)	title "Wirkstrom Enyaq 3P",\
     "corsa_e_one_phase_three_connected.csv"				using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(120/360.0,0.5,1.0)	title "Scheinstrom eCorsa 1P",\
     "corsa_e_one_phase_three_connected.csv"				using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(120/360.0,1.0,1.0)	title "Wirkstrom eCorsa 1P",\
     "zoe_r240_one_phase.csv" 								using ($2):($6)						with lines	lc rgbcolor hsv2rgb(140/360.0,0.5,1.0)	title "Scheinstrom R240 1P",\
     "zoe_r240_one_phase.csv"								using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(140/360.0,1.0,1.0)	title "Wirkstrom R240 1P",\
     "zoe_r240_three_phases.csv" 							using ($2):($25)					with lines	lc rgbcolor hsv2rgb(160/360.0,0.5,1.0)	title "Scheinstrom R240 3P",\
     "zoe_r240_three_phases.csv"							using ($2):($27/($48/sqrt(3))/3)	with lines	lc rgbcolor hsv2rgb(160/360.0,1.0,1.0)	title "Wirkstrom R240 3P",\
     "mg4_one_phase_three_connected.csv"					using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(180/360.0,0.5,1.0)	title "Scheinstrom MG4 1P",\
     "mg4_one_phase_three_connected.csv"					using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(180/360.0,1.0,1.0)	title "Wirkstrom MG4 1P",\
     "spring_45_comfort_plus_one_phase_three_connected.csv"	using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(200/360.0,0.5,1.0)	title "Scheinstrom Spring 1P",\
     "spring_45_comfort_plus_one_phase_three_connected.csv"	using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(200/360.0,1.0,1.0)	title "Wirkstrom Spring 1P",\
     "polestar_2_one_phase.csv"								using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(220/360.0,0.5,1.0)	title "Scheinstrom Polestar 2 1P",\
     "polestar_2_one_phase.csv"								using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(220/360.0,1.0,1.0)	title "Wirkstrom Polestar 2 1P",\
     "leaf_ze1_one_phase.csv"								using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(240/360.0,0.5,1.0)	title "Scheinstrom Leaf 1P",\
     "leaf_ze1_one_phase.csv"								using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(240/360.0,1.0,1.0)	title "Wirkstrom Leaf 1P",\
     "ariya_one_phase.csv"									using ($2):($6) 					with lines	lc rgbcolor hsv2rgb(260/360.0,0.5,1.0)	title "Scheinstrom Ariya 1P",\
     "ariya_one_phase.csv"									using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(260/360.0,1.0,1.0)	title "Wirkstrom Ariya 1P",\
     "ioniq_5_one_phase.csv" 								using ($2):($6)						with lines	lc rgbcolor hsv2rgb(280/360.0,0.5,1.0)	title "Scheinstrom Ioniq 5 1P",\
     "ioniq_5_one_phase.csv"								using ($2):($27/$3)					with lines	lc rgbcolor hsv2rgb(280/360.0,1.0,1.0)	title "Wirkstrom Ioniq 5 1P",\
     "ioniq_5_three_phases.csv"								using ($2):($25)					with lines	lc rgbcolor hsv2rgb(300/360.0,0.5,1.0)	title "Scheinstrom Ioniq 5 3P",\
     "ioniq_5_three_phases.csv"								using ($2):($27/$24/3)				with lines	lc rgbcolor hsv2rgb(300/360.0,1.0,1.0)	title "Wirkstrom Ioniq 5 3P"


pause mouse close
quit
