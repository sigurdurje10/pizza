# Verklegt Námskeið 1 - 2017 - hópur 30

Verkefnið snérist um að búa til þriggjalaga kerfi handa pizzustað
Meðlimir hóps 30:
  - Aron Ingi Tómasson
  - Sigurður Jökull Eydal Tómasson
  - Tómas Hrafn Jóhannesson

# Þriggjalaga hönnun!
Kerfið skiptist í:
  - UI klasa
  - Data klasa
  - Model klasa
Svo má einnig nefna services klasa og exception klasana líka. 


Í upphafs viðmótinu er hægt að velja:
  - Umsjón
  - Sala
  - Bakstur
  - Afhending
  - Solutölur
  - Nýskráning
  - Innskráning

## Umsjón
Hér getur notandi:
* Skrá stærð
* Skrá botn
* Skrá álegg
* Skrá matseðilspizzu
* Skrá pizzastað
* Skrá meðlæti

## Sala
Hér getur notandi:
* Skráð pöntun
    * Velur hvort pizza sé matseðils eða sérvalin
* Skráð pöntun með syntax
    * gerður til að auka hraðvirkni
* Séð heildarverð á pöntun
* Skráð pöntun senta eða sótta
* Skráð pöntun greidda
* Skráð afhendingarstað
* Skráð athugasemd
* Séð allar pantanir
    * Með upplýsingum eins og t.d. hvort að pizza sé ónýt osfrv.
* Eytt pöntun
## Bakstur
Hér getur notandi:
* Valið afhendingarstað og fengið aðeins pizzur sem eru skráðar þar.
* Listað allar virkar pizzur
    * Tilbúnar pizzur(pöntun merkt afhent) hverfa af listanum og fara í annað skjal. 
*  Séð upl. um eina pizzu
*  Merkt pizzu sem í vinnslu
*  Merkt pizzu sem tilbúna
## Afhending
Hér getur notandi:
* Valið afhendingarstað og fengið aðeins pantanir sem eru skráðar þar
* Séð lista af óafhentum(virkum) pöntunum. 
* Séð lista af tilbúnum pöntunum. 
* Skoðað virka pöntun
* Merkt pöntun sem greidda
* Merkt pöntun sem afhenta
* Séð lista af afhentum pöntunum
## Sölutölur
Hér getur notandi:
* Séð fjölda pantana sem hafa verið gerðar
* Séð fjölda pítsna sem hafa verið pantaðar
* Séð heildarveltu
* Séð fjölda viðskiptavina
* Skoða aðeins sölutölur frá ákveðinni dagsetningu(viðmótið virkar eins en skilar aðeins niðurstöðum frá ákveðinni dagsetningu t.d. heildarvelta myndi bara taka mið af pöntunum frá dagsetningunni sem var gefin)
* Skoða aðeins sölutölur á ákveðinni dagsetningu(viðmótið virkar eins en skilar aðeins niðurstöðum á ákveðinni dagsetningu t.d. heildarvelta myndi bara taka mið af pöntunum á dagsetningunni sem var gefin)

## Innskráning/Nýskráning
* Notandi getur skráð sig inn þannig að hann þarf ekki alltaf að velja hvar hann vinnur.
    * t.d. þarf bakari ekki að hafa áhyggjur af því að skrifa alltaf inn að hann vinni í skeifunni, hann loggar sig bara inn einu sinni.

# Umhverfi

Við notuðum eftirfarandi forrit:
* [CodeBlocks](http://www.codeblocks.org/downloads) - HTML to Markdown converter
* [QT](https://www.qt.io/) - duh

Og svo notuðum við GitHub.
Það nægir að sækja aðal forritið á github og keyra það í codeblocks.
Forritið er sótt með því að ýta á clone or download takkan á github og svo er valið download zip.
Forritið er þá sótt á tölvuna og svo getur notandi afþjappað því.

* [Github repo](https://github.com/sigurdurje10/pizza)



