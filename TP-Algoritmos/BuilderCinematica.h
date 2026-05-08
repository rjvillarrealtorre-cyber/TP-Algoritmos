#pragma once

#include "Utilidades.h"
#include "Cinematica.h"

Cinematica setupCinNvl1Inicio() {
	Cinematica cin;

	cin.agregarSlide({
		u8"▄▄  ▄▄ ▄▄ ▄▄ ▄▄      ▄██     ▄▄▄▄▄ ▄▄       ▄▄▄▄ ▄▄ ▄▄    ▄▄▄▄▄ ▄▄  ▄▄  ▄▄▄▄ ▄▄  ▄▄▄    ▄▄▄▄  ▄▄▄▄▄ ▄▄      ▄▄▄▄  ▄▄  ▄▄▄ ",
		u8"███▄██ ██▄██ ██       ██ ▀   ██▄▄  ██      ███▄▄ ██ ██    ██▄▄  ███▄██ ██▀▀▀ ██ ██▀██   ██▀██ ██▄▄  ██      ██▄█▄ ██ ██▀██",
		u8"██ ▀██  ▀█▀  ██▄▄▄    ██ ▄   ██▄▄▄ ██▄▄▄   ▄▄██▀ ██ ██▄▄▄ ██▄▄▄ ██ ▀██ ▀████ ██ ▀███▀   ████▀ ██▄▄▄ ██▄▄▄   ██ ██ ██ ▀███▀",
		u8" ",
		u8" ",
		u8"                  ┏━┓╻┏━┓   ┏━╸┏┓╻┏━╸     ┏━┓┏━╸╻  ╻ ╻┏━┓   ┏━╸┏━╸┏┓╻╺┳╸┏━┓┏━┓╻       ┏━┓┏━╸┏━┓╻ ╻                  ",
		u8"                  ┣┳┛┃┃ ┃   ┣╸ ┃┗┫┣╸      ┗━┓┣╸ ┃  ┃┏┛┣━┫   ┃  ┣╸ ┃┗┫ ┃ ┣┳┛┣━┫┃       ┣━┛┣╸ ┣┳┛┃ ┃                  ",
		u8"                  ╹┗╸╹┗━┛   ┗━╸╹ ╹┗━╸ ┛   ┗━┛┗━╸┗━╸┗┛ ╹ ╹   ┗━╸┗━╸╹ ╹ ╹ ╹┗╸╹ ╹┗━╸ ┛   ╹  ┗━╸╹┗╸┗━┛                  ",
		u8"                                                                                                                    ",
		u8"                                                                                                                    ",
		u8" ┃ ┏━┓╻ ╻┏━╸╺┳┓┏━╸   ╻ ╻┏┓╻   ┏━╸┏━┓┏━┓┏━┓┏━┓╺┳╸┏━╸┏━┓┏━┓   ┏━╸┏━┓┏━╸╻ ╻┏━╸╻ ╻┏━┓┏━┓   ╻ ╻┏┓╻┏━┓   ╻ ╻╻┏━┓╺┳╸┏━┓┏━┓╻┏━┓",
		u8"┏━ ┣━┛┃ ┃┣╸  ┃┃┣╸    ┃ ┃┃┗┫   ┣╸ ┃ ┃┣┳┛┣━┫┗━┓ ┃ ┣╸ ┣┳┛┃ ┃   ┣╸ ┗━┓┃  ┃ ┃┃  ┣━┫┣━┫┣┳┛   ┃ ┃┃┗┫┣━┫   ┣━┫┃┗━┓ ┃ ┃ ┃┣┳┛┃┣━┫",
		u8"┗━┛╹  ┗━┛┗━╸╺┻┛┗━╸   ┗━┛╹ ╹   ╹  ┗━┛╹┗╸╹ ╹┗━┛ ╹ ┗━╸╹┗╸┗━┛   ┗━╸┗━┛┗━╸┗━┛┗━╸╹ ╹╹ ╹╹┗╸   ┗━┛╹ ╹╹ ╹   ╹ ╹╹┗━┛ ╹ ┗━┛╹┗╸╹╹ ╹",
		u8"         ┏━┓╻ ╻┏━╸   ┏┓╻┏━┓   ┏━┓┏━╸   ┏━╸╻ ╻┏━╸┏┓╻╺┳╸┏━┓   ┏━╸┏━┓┏┓╻   ┏━┓┏━┓╻  ┏━┓┏┓ ┏━┓┏━┓┏━┓┏━┓                 ",
		u8"         ┃┓┃┃ ┃┣╸    ┃┗┫┃ ┃   ┗━┓┣╸    ┃  ┃ ┃┣╸ ┃┗┫ ┃ ┣━┫   ┃  ┃ ┃┃┗┫   ┣━┛┣━┫┃  ┣━┫┣┻┓┣┳┛┣━┫┗━┓ ╺┛                 ",
		u8"         ┗┻┛┗━┛┗━╸   ╹ ╹┗━┛   ┗━┛┗━╸   ┗━╸┗━┛┗━╸╹ ╹ ╹ ╹ ╹   ┗━╸┗━┛╹ ╹   ╹  ╹ ╹┗━╸╹ ╹┗━┛╹┗╸╹ ╹┗━┛ ╹                  ",
		u8"                                                                                                                    ",
		u8"                                                                                                                    ",
		u8"    ┏━ ╺┳╸┏━╸┏━╸╻  ┏━┓┏━┓   ╺┳┓╻┏━┓ ━┓   ┏━╸┏━┓┏┓╻╺┳╸╻┏┓╻╻ ╻┏━┓┏━┓         ┏━ ┏━╸┏━┓┏━╸ ━┓   ┏━┓┏━┓╻  ╺┳╸┏━┓┏━┓                   ",
		u8"    ┃   ┃ ┣╸ ┃  ┃  ┣━┫┗━┓    ┃┃┃┣┳┛  ┃   ┃  ┃ ┃┃┗┫ ┃ ┃┃┗┫┃ ┃┣━┫┣┳┛   ╺━╸   ┃  ┣╸ ┗━┓┃    ┃   ┗━┓┣━┫┃   ┃ ┣━┫┣┳┛                   ",
		u8"    ┗━  ╹ ┗━╸┗━╸┗━╸╹ ╹┗━┛   ╺┻┛╹╹┗╸ ━┛   ┗━╸┗━┛╹ ╹ ╹ ╹╹ ╹┗━┛╹ ╹╹┗╸         ┗━ ┗━╸┗━┛┗━╸ ━┛   ┗━┛╹ ╹┗━╸ ╹ ╹ ╹╹┗╸                   ",
		}, 8, 7);

	cin.agregarSlide({
		u8"“Remontar ese río era como viajar de  regreso a los primeros orígenes del mundo,",
		u8" cuando la vegetación se  desbordaba  sobre la tierra y los grandes árboles eran",
		u8" reyes. Un curso de agua vacío,  un  gran silencio, una selva impenetrable.   El",
		u8" aire era cálido, espeso, pesado,  lento. No había alegría en el fulgor del sol.",
		u8" [...] Y esa quietud de la vida no se parecía en absoluto a  la  paz.     Era la",
		u8" quietud  de  una  fuerza   implacable   que   se  cernía  sobre  una  intención",
		u8" inescrutable. Te miraba con un aire vengativo.”",
		u8"                                              — Joseph Conrad, Heart of Darkness",
		u8"",
		u8" Cuando viajé por primera a  través  del  Río  Ene, entendí por qué los nativos,",
		u8" entendí por qué  los  nativos  dicen  que  los  ríos  tienen alma. Turbulencia.",
		u8" Estruendo. Desasosiego. Extenuación. Era como si la Providencia, a través de la",
		u8" voz de la  naturaleza, estuviese  recitando  la  elegía  de la defunción de sus",
		u8" guardianes. Estuve así por tres largos días, acompañado, gracias a Dios, por un",
		u8" remero, el único que aceptó llevarme a Kametsa Pampa. Tres días de un calor so-",
		u8" focante, de mosquitos zumbando  en  el oído, y de sentir en carne propia la Ira",
		u8" de Dios... un  concepto  no  ajeno   ni   a   los nativos ni a los exploradores",
		u8" españoles que penetraron estas faces hace cinco centurias.",
		u8"",
		u8" Yo no soy tan diferente a  ellos. Yo  también  estoy  movido  por la codicia...",
		u8" de conocimiento. Ansias por descubrir, no  solo la verde beldad de Natura, sino",
		u8" de aquello que no se cuenta con palabras.",
		u8" De lo que todos parlan con laudable actitud,  de  aquello que todos buscan pero",
		u8" que pocos defienden: la Verdad (sí, con mayúscula)..."
		}, 29, 5);

	cin.agregarSlide({
		u8" Llamádme Mateo.  Soy periodista  de  profesión. 12 años en la carrera, 7 de los",
		u8" cuales pasé en Crónica Viva.",
		u8"",
		u8" Ah, Crónica Viva.  Famosa en su inexistente fama e infame por su crudo impacto.",
		u8" Una revista cualquiera que no resalta en nada: ni en la verborrea de sus escri-",
		u8" tores ni en el carisma de sus  presentadores... salvo  por el único aspecto que",
		u8" de verdad importa: su inquebrantable monomanía por la VERDAD.",
		u8"",
		u8" He viajado por toda la patria.  He seguido los rastros de organizaciones crimi-",
		u8" nales en Lima, he cubierto derrames mineros  en  Pasco,  desapariciones  en  el",
		u8" VRAEM... siempre  armado  con  nada  más  que  una  grabadora, una cámara y  mi",
		u8" verboso ser. Pero nunca, nunca... me he adentrado tanto en la selva...",
		u8"",
		u8" Lo que me trajo aquí: fotografías satelitales.  Obscuridad sobre el manto verde",
		u8" de la Amazonía. Y un dato: en los últimos dos años, ningún periodista ha llega-",
		u8" do a Kametsa Pampa. Los que lo intentaron cambiaron misteriosamente su rumbo en",
		u8" el camino, o regresaban con una lacónica explicación de su laxitud.",
		u8" ",
		u8" Antes de partir, mi editor me dijo: 'Consigue la historia.  Pero no te metas en",
		u8" problemas. Parece que se le olvidó que nosotros somos EL problema..."
		}, 29, 7);

	cin.agregarSlide({
		u8" En la noche del tercer día, paramos en el sendero que conducía hacia Puerto Es-",
		u8" peranza— nombre en  castellano  cuya  peculiaridad no podía ignorar. El remero,",
		u8" sin embargo, se negó a  llevarme,  mas  accedió a acompañarme a pasar la última",
		u8" noche conmigo. Al amanecer, y antes de partir, me suplicó que sea cauto.",
		u8" Y así, sin darme más explicaciones, se marchó río abajo.",
		u8" ",
		u8" El sendero había sido obscurecido por la gruesa neblina. No había más ruido que",
		u8" mi propia respiración, el  sonido  del agua fluyendo y algunos monos aulladores",
		u8" que chillaban en la distancia. La selva me miraba con un aire vengativo.",
		u8"",
		u8" Y me di cuenta que no estaba solo.  Dos hombres, jóvenes, robustos, se pusieron",
		u8" en cada uno de mis costados. Intenté mantener la calma... pero,  ¿cómo no hacer",
		u8" la tan obvia conexión entre datos supuestamente tan dispares?   Los periodistas",
		u8" que cambiaban su rumbo, los murmullos del remero, y esta extraña presencia...",
		u8"",
		u8" HOMBRE 1: ¿Periodista, eh? Te estábamos esperando."
		u8" ",
		u8" Una mísera noche y ya había sido marcado, ¡Cómo me sonreía el sino!",
		u8" Hice lo que pude para contener una risilla histérica.  Era  todo tan abusurdo,",
		u8" pero a la vez tan obvio que me sentí el hombre más estúpido del mundo."
		u8" ",
		u8" HOMBRE 2: El monte es grande, foreastero. Fácil perderse. Y nadie va a ayudarte."
		}, 29, 7);

	cin.agregarSlide({
		u8" El primero se acercó más. Pude oler el fantasma del tabaco en su aliento y las",
		u8" manchas de aceite en su torso. Tenía en su faz una sonrisa burlona, y sus ges-",
		u8" tos estaban manchados hasta el tuétano con una parsimonia agobiante.  Era cómo",
		u8" si fuese un profesor lidiando con un lerdo infante.",
		u8"",
		u8" HOMBRE 1: Mira, te voy a dar un consejo. Tú tomas tus fotos bonitas,  escribes",
		u8" tu nota y te largas río abajo. En dos días llegas a  Satipo.  En  dos  más,  a",
		u8" Lima... Piensa en tu familia. En  tu  carrera.  Y  en  el brillante futuro que",
		u8" tienes por delante. Aquí no hay historia, solo gente que no quiere hablar  con",
		u8" extraños, ¿Entendiste?",
		u8"",
		u8" El segundo hombre no se molestó en hablar, respondiendo con  una  carcajada  a",
		u8" pulmón junto a  una  peculiar  mirada:  dudando  si  verme con la pena que uno",
		u8" siente al ver a un  desquiciado,  o con la molestia que invade cuando ves a un",
		u8" insecto.",
		u8"",
		u8" No les respondí.  Consentir  era  futil.  Hablar  era  darles  bagatelas. Y el",
		u8" silencio... era temerario...",
		u8" ",
		u8" No se marcharon. Simplemente marcharon algunos pasos sendero arriba y se  que-",
		u8" daron allí, observando, y esperando ¿A qué? ¿A qué abriera la boca? ¿O buscan-",
		u8" la razón para que su florida verborrea evolucione al poco elegante arte de los",
		u8" puños?"
		}, 29, 6);

	return cin;
}

Cinematica setupCinNvl1Final() {
	Cinematica cin;

	cin.agregarSlide({
		u8" La brisa sopla, mesiendo los árboles, los arbustos y la maleza. Un manto dorado",
		u8" cubre el pasto donde estoy reposando.  Es el crepúsculo.  En menos de una hora,",
		u8" el sol se esconderá completamente, abriendo paso a la luna, cumpliendo la eter-",
		u8" na pero necesaria dualidad entre la luz y la oscuridad. Miro al horizonte. Sien",
		u8" to que la naturaleza me susurra, me atrapa, me seduce. ¿Y si de verdad las plan",
		u8" tas tienen alma? Me pregunto, mientras fumo un poco del tabaco que el Abuelo To",
		u8" más me dio esa misma mañana.",
		u8"",
		u8" Ahí es cuando siento una presencia detrás de mí. Antes de que pueda reaccionar,",
		u8" siento una mano en mi hombro. Alzo la mirada. Reconozco inmediatamente ese ros-",
		u8" tro. Es Wilmer. Está más cansado que cuando lo vi por primera vez, esa misma ma",
		u8" ñana, pero hay una extrañeza en su faz. Un sutil, traicionero, rayo de esperan-",
		u8" za. Se me queda observando por un largo intervalo, hasta que rompe el silencio.",
		u8"",
		u8" WILMER: Le caíste bien a Doña Rosa. Mamá Clara preguntó por ti.  Don Tomás dice",
		u8" que sabes escuchar. Estoy sorprendido... Eso es raro en un forastero.",
		u8"",
		u8" Hace una pausa, dudando si cruzar el umbral del que jamás regresará.",
		u8"",
		u8" WILMER: El Abuelo Evaristo quiere verte."
		}, 29, 7);

	cin.agregarSlide({
		u8" Caminamos un largo sendero en total silencio. No es la lúgubre carencia de soni",
		u8" do de las interminables noches de viaje. Es algo diferente. Lleno en su flaque-",
		u8" za. Los últimos sonidos distantes,  los murmullos, los gritos,  la indiscutible",
		u8" VIDA de un pueblo que se niega a fenecer, desaparece a nuestras espaldas.  Y la",
		u8" naturaleza, tan atenta, parece notar este hecho.",
		u8" ",
		u8" WILMER: Don Evaristo es el líder del pueblo. Él es el último que lo recuerda to",
		u8" do. Nuestra fundación. Los nombres de nuestros ancestros. Los lugares donde so-",
		u8" líamos pescar y cosechar nuestros cultivos.  Los cantos tradicionales y los ri-",
		u8" tuales que abundaban antes que llegaran los madereros.  Por eso es que le tene-",
		u8" mos tanto respeto. Porque es la personificación del pueblo.   Si él se va, todo",
		u8" el pueblo se va con él.",
		u8"",
		u8" MATEO: ¿Y por qué no se lo enseña todo lo que sabe a la juventud?   Al fin y al",
		u8" cabo, alguna vez él también fue joven.   Y no hay más regalo más grande que dar",
		u8" la responsabilidad de la superviviencia de un pueblo a las futuras generaciones",
		u8"",
		u8" WILMER: Antes había comunión con la naturaleza. El hombre y la tierra eran uno.",
		u8" No se parasitaba. Se daba y se recibía. Y fue así por siglos. Y gracias a ello,",
		u8" es que nuestro pueblo se mantuvo saludable. Pero con los madereros, eso se rom-",
		u8" pió. Los jóvenes nacieron desarraigados.  Rechazan la tierra, por que la tierra",
		u8" ellos creen, los rechazó. Y ellos se van. O trabajan para ellos.  O simplemente",
		u8" mueren muy jóvenes. Y los que quedamos... estamos cansados."
		u8" ",
		u8" Reanuda la marcha. El sendero se estrecha. Las ramas nos arañan los brazos.",
		}, 29, 5);

	cin.agregarSlide({
		u8" El sendero desemboca en un claro. Allí, solitaria, hay una ceiba gigante.   Mi",
		u8" vida en Lima pasa por mi mente al verla. Es tan alta como esos edificios resi-",
		u8" denciales que abundan en San Isidro, o en Jesús María.   Y es tan ancha que se",
		u8" se necesitaría más de cinco hombres para abrazarla.",
		u8"",
		u8" Al costado, una cabaña de madera. Y un techo de palma.  Es pequeña, pero bien ",
		u8" cuidada.   Y mentiría si digo que no sentí un estallido de emociones al verla.",
		u8" Tiene ese aire peculiar de los lugares que sienten, que recuerdan millares  de",
		u8" recuerdos, de cuitas, de alegrías.",
		u8"",
		u8" De la chimenea sale un humo blanco. Y lo puedo distinguir. Huele a tabaco. Qui",
		u8" zás sea el mismo que me dio Don Tomás, y el cuál aún no había acabado.",
		u8"",
		u8" WILMER: Esta parte es tuya, Mateo. Yo no puedo entrar contigo.",
		u8"",
		u8" Su mirada, furtiva, logra fijarse en mi ser.  Hay una advertencia en sus ojos.",
		u8"",
		u8" WILMER: No le mientas. No le prometas nada que no vayas a cumplir. Y sobre to-",
		u8" do, escucha. Es lo que más nos falta a todos, después de todos."
		}, 29, 7);

	cin.agregarSlide({
		u8" Wilmer se aparta. Estoy completamente solo ante el peligroso umbral. ¿Pero que",
		u8" es mi vida sin este tipo de exaltación?  A lo largo de mi vida, he aprendido a",
		u8" vivir peligrosamente. Y es lo que me ha llevado hasta donde estoy. Pero nunca,",
		u8" nunca, me había  sentido  tan...  débil. Sabía cómo controlar mis nervios ante",
		u8" las amenazas, las extorsiones, los ataques bajos. Pero nunca había lidiado con",
		u8" mi propia incertidumbre...",
		u8"",
		u8" Volteo la cabeza. Wilmer ha desaparecido.  Recuerdo los anteriores reportajes.",
		u8" Aquel reporte de la minería ilegal en Pasco, y del cual volví con una historia",
		u8" indiscutible,  y después del cuál me llovieron muchos agradecimientos en forma",
		u8" de casquillos de bala en mi puerta. Ya estaba acostumbrado al riesgo... Y vol-",
		u8" ví a confirmar que este riesgo era diferente.   Pensé: ¿Cuál es la diferencia?",
		u8"",
		u8" La respuesta estaba alrededor, detrás, y frente mío. El costo social. La admi-",
		u8" ración genuina y el asombro causado por la tenacidad de un pueblo, de la sabi-",
		u8" duría de sus líderes... y un pesar ahogante por el sufrimiento de 'Kipatsi'...",
		u8"",
		u8" No lo pienso más. Empujo la puerta, la cuál había sido dejada convenientemente",
		u8" entreabierta. Las bisagras gimen ante mi invasión.",
		u8"",
		u8" EVARISTO: Pasa, periodista. Te estábamos esperando.",
		u8"",
		u8" No lo logro ver. Pero sé que está ahí. Que... 'ellos' están allí.",
		}, 29, 5);

	return cin;
}