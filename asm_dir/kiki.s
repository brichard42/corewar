.name "Canaries des Iles 
		Volant gaiement 
		Voila
		Ah au fait je m'appelle KIKI et je suis pas aussi gentil
		ke Jean nez l'aire"

.comment "Plantation Iroquoise 
#		Canne à sucre
#
#
		Et Pomme de Terre !                           
		
		"

live: zjmp %:live_5

graou_le_miaou:
live_5: #Test du commentaire après un label
	live %16
	live %-16165416549846516849841684 #Test nombre SUPER grand et neg
	ld	%4, r9
	fork %1024
	lfork %4096

test_label_pas_inline_et_avec_un_nom_long_long_long_long_y_c_o_100_ty_a_go:
                                     st													r2              ,                     -666
sti r1,%:test_label_pas_inline_et_avec_un_nom_long_long_long_long_y_c_o_100_ty_a_go,%1
		live			                 %-98745

test_inline_label: zjmp %:live
	zjmp %:live
	zjmp %:test_inline_label
	add	r6,r6,r11
	fork %42

test_label_alone:
	#c vide!
