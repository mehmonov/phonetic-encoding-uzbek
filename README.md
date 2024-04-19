# phonetic-encoding-uzbek
O'zbekcha so'zlarni fonetik, ya'ni ohangdoshligi bo'yicha kodlash

Metaphone kabi algoritmlarlar o'zbek tilidagi so'zlar uchun to'g'ri kod berolmaydi, sababi boshqa tillarga moslangan. 
Ushbu kod o'zbek tilidagi harflarni hisobga olgan holda Metaphone ning o'zgartirilgan variantidir.

Masalan: Metaphone orqali "Poytaxt" va "Poytaht" so'zlariga ikki hil, bir-biridan farq qiluvchi kod beriladi.
```
metaphone("Poytaxt") = "PTKST"
metaphone("Poytaht") = "PTT"
```
Vaholanki o'zbek tilida ikki so'zning o'zbek tilida o'qilishi deyarli bir hil.

O'zgartirilgan variantda
```
encode("Poytaxt") = "PYTX"
encode("Poytaht") = "PYTX"
```
