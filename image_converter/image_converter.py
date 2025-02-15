from PIL import Image

fold = "image_to_convert/"
# Charger l'image du donjon (le sol) et du sprite
donjon = Image.open(fold + '0.xpm')  # Remplace par ton fichier XPM du donjon
sprite = Image.open(fold + '21.xpm')  # Remplace par ton fichier XPM du sprite

# Convertir les deux images en mode RGBA pour travailler avec la transparence
donjon = donjon.convert("RGBA")
sprite = sprite.convert("RGBA")

# Obtenir les données des pixels
donjon_data = donjon.load()
sprite_data = sprite.load()

# Parcourir tous les pixels du sprite
for y in range(sprite.height):
    for x in range(sprite.width):
        # Si le pixel du sprite est transparent (None ou alpha=0), le remplacer par la couleur du donjon
        sprite_pixel = sprite_data[x, y]
        if y == 0 or sprite_pixel[3] == 0:  # Vérifier si le pixel est transparent
            donjon_pixel = donjon_data[x, y]
            sprite_data[x, y] = donjon_pixel  # Remplacer par la couleur du donjon

# Sauvegarder l'image résultante
sprite = sprite.convert("RGBA")
sprite.save('ground_00.png')  # Sauvegarder le sprite modifié

sprite.show()  # Afficher le résultat
