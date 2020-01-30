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
	fork %17    # pour aller a spartiate_quelle_est_votre_metier
	lfork %4096

test_label_pas_inline_et_avec_un_nom_long_long_long_long_y_c_o_100_ty_a_go:
                                     st													r2              ,                     -666
# 1 (OPCODE) +  1 (PARAM BYTE) + 1 (REGISTRE) + 2 (INDIRECT VALUE)
# = 5

sti r1,%:test_label_pas_inline_et_avec_un_nom_long_long_long_long_y_c_o_100_ty_a_go,%1
# 1 (OPCODE) +  1 (PARAM BYTE) + 1 (REGISTRE) + 2 (DIRECT VALUE) + 2 (DIRECT VALUE)
# = 7

		live			                 %-98745
# 1 (OPCODE) + 4 (DIRECT VALUE)
# = 5

# Total = 5 + 7 + 5 = 17

spartiate_quelle_est_votre_metier:
	ld		%73, r2
	aff		r2			#  I

	ld		%32, r2
	aff		r2			#  ' '

	ld		%65, r2
	aff		r2			#  A
	ld		%77, r2
	aff		r2			#  M

	ld		%32, r2
	aff		r2			#  ' '

	ld		%75, r2
	aff		r2			#   K
	ld		%73, r2
	aff		r2			#   I
	ld		%75, r2
	aff		r2			#   K
	ld		%73, r2
	aff		r2			#   I

	ld		%33, r2
	aff		r2			#  '!'

	zjmp	%:spartiate_quelle_est_votre_metier



test_inline_label: zjmp %:live
	zjmp %:live
	zjmp %:test_inline_label
	add	r6,r6,r11
	fork %42

test_label_alone:
	#c vide!
