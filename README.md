# phonetic-encoding-uzbek
O'zbekcha so'zlarni fonetik, ya'ni ohangdoshligi bo'yicha kodlash

Metaphone kabi algoritmlarlar o'zbek tilidagi so'zlar uchun to'g'ri kod berolmaydi, sababi boshqa tillarga moslangan. 
Ushbu kod o'zbek tilidagi harflarni hisobga olgan holda o'zgartirilgan algoritmdir.

Masalan: Metaphone orqali "Poytaxt" va "Poytaht" so'zlariga ikki hil, bir-biridan farq qiluvchi kod beriladi.
```
metaphone("Poytaxt") = "PTKST"
metaphone("Poytaht") = "PTT"
```
Vaholanki o'zbek tilida ikki so'zning o'zbek tilida o'qilishi deyarli bir hil.

Mani o'zgartirilgan variantimda
```
encode("Poytaxt") = "PYTXT"
encode("Poytaht") = "PYTXT"
```
