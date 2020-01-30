.name "Canaries des Iles 
		Volant gaiement 
		Voila"

.comment "#aPlantation Iroquoise 
		Canne à sucre #fewfw


		Et Pomme de Terre !                           
		
		"

live: zjmp %:live_5

live_5: #Test du commentaire après un label
	live %16
	live %16
	ld	%4, r3

test_inline_label: zjmp %:live
	zjmp %:live
	zjmp %:test_inline_label
	add	r6,r6,r11
	fork %42


#test_label_alone:
	#c vide!
