#pragma once

NPCInteractuable setupNINivel1Mapa1Lenador1() {
    std::vector<Opcion> opciones0 = {
        {u8"Increparlo", {0,0,1}, 1},
        {u8"Preguntar acerca de los anteriores periodistas", {0,0,1}, 3, 0},
        {u8"Preguntar de Kametsa Pampa", {0,0,1}, 4, 0},
        {u8"Preguntar acerca de él", {0,0,1}, 5, 0},
    };

    std::vector<Opcion> opciones1 = {
       {u8"Quería decir algo más...", {0,0,0}, 0},
    };

    Dialogo d0({
        u8"LEÑADOR 1: ¿Te quedó  alguna  duda,  periodista? He sido bastante claro contigo,",
        u8"¿o quieres que te lo explique con manzanitas? Creo que eres alguien inteligente,",
        u8"así que hazme caso, y todos salimos ganando."
        }, opciones0);

    Dialogo d1({
        u8"MATEO: Te estás confundiendo. Yo no soy como los anteriores periodistas.  Yo sí tengo",
        u8"escrúpulos, y una patológica obsesión por la verdad.  He lidiado con la gente, con la",
        u8"clase luchadora y con charlatanes. Aunque no lo parezca, ¡y qué bien que no lo haga!,",
        u8"tengo experiencia lidiando con indeseables.  Y no soy estúpido. Sé como funciona este",
        u8"juego, y tomé las  precauciones  necesarias  antes de partir. Aunque debo agredecerte",
        u8"por la cordial bienvenida. Me aseguraré de incluirlo en la nota.",
        u8"                          [Presiona E para continuar]"
        }, 2);

    Dialogo d2({
        u8"LEÑADOR 1: Oh, no te molestes. Yo solo intentaba ser amable. Viendo que eres un mal-",
        u8"criado, actuaré como  tal.  Te  recomiendo vigilar tus espaldas, periodista. Aquí el",
        u8"conocimiento tiene precio, y tú no tienes como pagarlo.",
        u8"Lamentaría que tu balsa  se  hunda,  que  tu  comida  sorpresivamente te haga mal, o",
        u8"que se oigan rumores que pongan al pueblo contra ti. Imagínate... 'Periodista limeño",
        u8"desaparece tras un viaje a la selva'... Lárgate. No perderé el tiempo contigo."
        }, opciones1
    );

    Dialogo d3({
        u8"LEÑADOR 1: ¿Oh, los otros periodistas? No lidiamos con ellos desde hace dos largos  años.",
        u8"Los que se aventuraron cambiaban su rumbo tras peculiares emergencias, o desertaban antes",
        u8"de sarpar. Claro, algunos llegaron  aquí... pero tras una amical charla los convencimos a",
        u8"no hurgar donde no tenían negocio  alguno.  Ellos fueron muy cooperativos.  Espero que tú",
        u8"también lo seas."
        }, opciones1);

    Dialogo d4({
        u8"LEÑADOR 1: Un pueblecillo  infame  por  su  pasión  por la agresión gratuita. ¿Sabías que el",
        u8"susodicho líder del pueblo, Evaristo, fue denunciado penalmente, por usurpación de terrenos?",
        u8"Este hombre y su  gente  fue  tan  fresca  de  invadir tierra que pertenence legalmente a la",
        u8"maderera. ¿Qué  se  puede  esperar de esa calaña? Odian a los forasteros. Odian a los traba-",
        u8"dores como yo, y ciertamente, no se molestarán en decirte ni una sola palabra."
        }, opciones1);

    Dialogo d5({
        u8"LEÑADOR 1: ¿Yo?  Solo soy un trabajador encargado a vigilar esta zona, que legalmente le",
        u8"pertenece a la empresa en la  que  trabajo y la cuál ha sido tristemente agregida por la",
        u8"comunidad nativa. ¿Te imaginas? Nos han atacado constantemente, y quién sabe que hubiese",
        u8"pasado si no hubiese sido  por  la intervención de la justicia. Desde ese momento, están",
        u8"tranquilos. Sería una lamentable si algún agitador viniese a quebrar la paz..."
        }, opciones1);

    ArbolDialogo arbl1;
    arbl1.agregarDialogo(d0, 0);
    arbl1.agregarDialogo(d1, 0);
    arbl1.agregarDialogo(d2, 0);
    arbl1.agregarDialogo(d3, 0);
    arbl1.agregarDialogo(d4, 0);
    arbl1.agregarDialogo(d5, 0);

    NPCInteractuable lenador1(u8"HOMBRE 1", {
        {" ", " ", " ", "_"},
        {"<", "|", " ", u8"Ø"},
        {" ", "|", u8"—", "|>"},
        {" ", " ", "/", "|"},
        }, 52, 16, arbl1);

    return lenador1;
}

NPCInteractuable setupNINivel1Mapa1lenador2() {
    NPCInteractuable lenador2(u8"HOMBRE 2", {
        {" ", " ", " ", "_"},
        {"<", "|", " ", u8"Ø"},
        {" ", "|", u8"—", "|>"},
        {" ", " ", "/", "|"},
        }, 59, 14);

    return lenador2;
}

NPCInteractuable setupNINivel1Mapa2Wilmer() {
    // NPCs

    std::vector<Opcion> opciones0 = {
        {u8"Así que me estaban esperando...", {0,0,1}, 1},
        {u8"¿Los Mudo?", {0,0,1}, 2},
        {u8"¿Solo una molestia menor? ¿Te estás refiriendo a los anteriores periodistas, no?", {0,0,1}, 3},
        {u8"[Asentir con la cabeza y no decir nada]", {0,0,1}, 4},
    };

    std::vector<Opcion> opciones1 = {
        {u8"[Asentir con la cabeza]", {0,0,0}, 4},
        {u8"Quisiera preguntarte algo más... [Volver]", {0,0,0}, 0},
    };

    Dialogo d0({
        u8"WILMER: Ah... es el periodista. No creas que has pasado desapercibido. Supimos que al-",
        u8"guien iba a llegar cuando Los Mudo empezaron a actuar diferente. No estaban nerviosos,",
        u8"solo irritados. Otra molestia más, aunque menor, que tenían que lidiar."
        }, opciones0);

    Dialogo d1({
        u8"WILMER: Sí, y no te debería sorprender.   ¿Escuchaste de los otros periodistas, no? Se",
        u8"desanimaban en  medio del camino.   Así pasó durante los dos últimos años.  Recibíamos",
        u8"rumores de sus inminentes llegadas... y nadie pisó ni la orilla. Ciertamente, has sido",
        u8"la excepción a la regla."
        }, opciones1);

    Dialogo d2({
        u8"WILMER: Bueno, es un mal ejemplo para tu caso, ¡siendo que has tenido larga charla con",
        u8"ellos! Nunca lo había visto tan de cerca, ¡Parece que tienen muy buena labia! Pero va-",
        u8"yamos al grano.  Los llamamos así por que nunca hablan con nadie, ni siquiera entre e-",
        u8"llos mismos... salvo que quieran convencer a alguien, como lo hicieron contigo..."
        }, opciones1);

    Dialogo d3({
        u8"WILMER: Sí, y quizás estoy siendo muy generoso con su impacto.  Nuestros amigos perio-",
        u8"distas se desviaban del camino, y los pocos que llegaron, dieron mala fama a su profe-",
        u8"sión.  ¿Luchar por la verdad?  Ellos solamente tomaban fotos a la aldea y al sol mien-",
        u8"tras evitaban los tocones o el río. Luego se largaban, y la aldea quedó igual, o peor."
        }, opciones1);

    Dialogo d4({
        u8"WILMER:  Periodista, entenderás mi inquietud al verte.  Eres el primero en pisar estas",
        u8"tierras en dos años, pero  no  creas que no hemos lidiado con tus compañeros de oficio",
        u8"tiempo atrás. ¿Los Mudo lograron convencerte, eh? ¿O de verdad quieres venderte  como",
        u8"la excepción a la regla?",
        u8"",
        u8"                             [Presiona E para continuar]"
        });

    std::vector<Opcion> opciones2 = {
        {u8"No me dejé convencer. Por eso no me marché. Quiero ser la excepción a la regla.", {5,0,0}, 6},
        {u8"Ya lo dijiste. Soy periodista. Vine a hacer mi trabajo, nada más.", {0,0,0}, 7},
        {u8"No tengo por qué contarle mis intenciones a nadie.", {-5,0,0}, 7}
    };

    std::vector<Opcion> opciones3 = {
        {u8"Vengo de estar con los pobladores. He aprendido mucho. [MIN. CONF: 30] [ACABAR NIVEL]", {0,0,0}, 7, 30, 0, true},
    };

    Dialogo d5({
        u8"WILMER: Así que, ¿Qué quieres aquí?  ¿Vas a tomar sus recomendaciones, y venderle men-",
        u8"tiras al mundo, o marcharte misteriosamente esta misma tarde?",
        }, opciones2);

    Dialogo d6({
        u8"WILMER: Ah... te crees diferente. Y en parte, lo eres. No te has marchado aún.  Ese es",
        u8"un  logro.  Hablas  con  coraje,  y  no  con  las  excusas  pusilánimes  de los que te",
        u8"precedieron. Pero te digo desde ya: la confianza no se regala, se gana.  Si eres dife-",
        u8"rente, demuéstralo. Hay muchos de nosotros que necesitan un par de brazos más.  Quizás",
        u8"así puedas mostrarnos, a todos, que tus palabras concuerdan con tus actos."
        }, opciones3);

    Dialogo d7({
        u8"WILMER: ¿Así que todo el espectáculo fue para nada? Vamos, en realidad no me sorprende",
        u8"en lo absoluto. Pero, en caso quieras cambiar de opinión, y demostrar que de verdad e-",
        u8"res alguien que vale la pena, actúa. No con palabras bonitas, sino con actos valiosos.",
        u8"El pueblo necesita ayuda. Y tú puedes ofrecérsela.",
        }, opciones3);

    ArbolDialogo arbl0;
    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);
    arbl0.agregarDialogo(d5, 0);
    arbl0.agregarDialogo(d6, 0);
    arbl0.agregarDialogo(d7, 0);

    NPCInteractuable wilmer(u8"Wilmer", {
        {" ", " ", u8"¥", u8" "},
        {"|", " ", u8"O", u8" "},
        {"|", "/", u8"|", u8">"},
        {" ", "/", u8"|", u8" "},
        }, 15, 11, arbl0);

    return wilmer;
}

NPCInteractuable setupNINivel1Mapa2Kevin() {
    std::vector<Opcion> opciones0 = {
        {u8"Se llaman trenes eléctricos. Y quizás se puede decir que vuelan...", {0,0,0}, 1},
        {u8"No, es una exageración. Son trenes peculiares, nada más.", {0,0,0}, 2},
    };

    Dialogo d0({
        u8"[Kevin está sentado, jugando con un palito en la chacra. Es pequeño, quizás de 10 a 12",
        u8"años. Al verte, te mira extrañado. Su expresión es curiosa, y no agresiva]",
        u8"KEVIN: ¡Ey! ¿Eres tú el periodista, ese que Wilmer mencionó?  ¡Wow! ¡Pensé  que nunca",
        u8"más volvería a ver uno! ¿Vienes de Lima, no? ¿Es verdad que ahí hay trenes que vuelan?"
        }, opciones0);

    std::vector<Opcion> opciones1 = {
        {u8"Está bien, pero por un momento. Y la cuidas, por favor.", {1,0,0}, 3},
        {u8"Lo siento, es mi herramienta de trabajo. No puedo.", {0,0,0}, 4},
    };

    Dialogo d1({
        u8"KEVIN:  ¿Trenes eléctricos?  ¿Vuelan gracias a la electricidad?  ¡Espero algún día ver",
        u8"uno!  Pero, ey, ¡aún hay mucho tiempo por delante!  ¿Y sí eres periodista?  ¿Qué es lo",
        u8"que haces? ¿Entrevistas gente? ¿Investigas casos peligrosos?  ¿Siempre llevando tu cá-",
        u8"mara? ¿Me la puedes dar, por un ratito? Quisiera grabar a mi abuela cantar. Ella canta",
        u8"bonito en asháninka."
        }, opciones1);

    Dialogo d2({
        u8"KEVIN:  Oh... Wilmer siempre exagera las cosas.  Pero eso no quita que son trenes.  ¡Y",
        u8"trenes peculiares! Yo nunca vi un tren.  Ni carros.  Solo las motos que algunos de los",
        u8"cinos tienen. Pero tú eres de Lima... ¿Periodista, sí?  ¿Qué es lo que haces?  ¿Grabas",
        u8"gente? ¿Me puedes dar tu grabadora, un ratito?  Quisiera grabar a mi abuela cantar. E-",
        u8"lla canta bonito en asháninka."
        }, opciones1);

    std::vector<Opcion> opciones3 = {
        {u8"¿Algo más? ¿Qué es lo que pasa?", {5,5,5}, 5},
    };

    Dialogo d3({
        u8"KEVIN: ¡Gracias, gracias! ¡Ahora vuelvo! [Kevin toma la cámara y entre tropezones, de-",
        u8"saparece  entre las cabañas.  Pasan algunos minutos, y se le puede observar en la dis-",
        u8"tancia. Tiene una sonrisa nerviosa en el rostro]",
        u8"¡Lo hice! ¡Grabé a mi abuelita! Pero... también grabé algo más."
        }, opciones3);

    std::vector<Opcion> opciones4 = {
        {u8"Cambié de opinión. Ten, tómala, pero cúidala mucho, y regresa rápido.", {0,0,0}, 3},
    };

    Dialogo d4({
        u8"KEVIN: Oh... está bien. Mi papá me dice que no debemos prestar las cosas importantes a",
        u8"desconocidos. Pero, si te animas, puedes volver. Yo estoy aquí. Yo siempre estoy aquí.",
        }, opciones4);

    std::vector<Opcion> opciones5 = {
        {u8"¿Le 'pegaron' a Wilmer?", {0,0,1}, 6},
    };

    Dialogo d5({
        u8"[Kevin reproduce la grabación. La vista no es muy clara, pero se pueden distinguir si-",
        u8"luetas evidentemente masculinas con ropas extrañamente similares a los hombres que  me",
        u8"arrinconaron en la orilla. Se escuchan voces distorsionadas: 'el cargamento...  mañana",
        u8"por la... quebrada Yonkiri... que nadie se entere...]",
        u8"KEVIN: Ellos son los hombres malos, ¿verdad? Los que le pegaron a Wilmer... No les di-",
        u8"gas que yo fui. Ellos piensan que solo soy un niño, que no entiende que pasa..."
        }, opciones5);

    Dialogo d6({
        u8"KEVIN: ¡Sí! Ocurrió el año pasado. Era cuando aún podíamos jugar y trabajar en la que-",
        u8"brada Yonkiri. Mi papá estaba pescando, y yo me escabullí con mis amigos en las cerca-",
        u8"nías.   Ahí fue cuando lo vimos... Wilmer y unos vecinos increparon a un hombre que se",
        u8"veía raro. Él se fue, pero rapidito volvió con otros más. Y los golpearon con palos...",
        u8"De allí se fueron. No entendí lo que pasaba. Pero no lo puedo olvidar...",
        }, 6);

    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);
    arbl0.agregarDialogo(d5, 0);
    arbl0.agregarDialogo(d6, 0);

    NPCInteractuable kevin(u8"Kevin", {
        {" ", "o", " "},
        {"<", "|", ">"},
        {" ", "<", ">"},
        }, 76, 17, arbl0);

    return kevin;
}

NPCInteractuable setupNINivel1Mapa2Rosa() {
    std::vector<Opcion> opciones0 = {
        {u8"[Asentir con la cabeza y ayudarla]", {5,10,0}, 1},
        {u8"¿Qué...?", {0,0,0}, 2},
    };

    std::vector<Opcion> opciones0_1 = {
        {u8"[Asentir con la cabeza y ayudarla]", {5,10,0}, 1},
    };

    Dialogo d0({
        u8"[Doña Rosa.  Está forcejeando con un cesto  evidentemente pesado de lo que  parece ser",
        u8"|yuca. Para. Te observa. Apunta el cesto, luego una casa al otro lado del pueblo]",
        u8"DONA ROSA: Hijo mío,  necesito llevar estas yucas hacia mi cabaña.  ¿Podrías ayudarme?",
        u8"Mi cuerpo ya no estan fuerte como era antes.  Así de inclemente es el paso del tiempo."
        }, opciones0, false);

    Dialogo d1({
        u8"[Tomo el cesto.  Es más pesado de lo que parece,  y el inclemente calor matutino no es",
        u8"de gran ayuda ante tanto esfuerzo físico. Ella va al lado mío. Por un momento, descan-",
        u8"so,  y la observo.  Puedo ver una sonrisa esbozada en su rostro.  Los demás pobladores",
        u8"me miran con gestos curiosos, algunos abiertamente anodados. ¿Es esto una prueba?]",
        u8"                             [Presione E para continuar]                              "
        }, 3);

    Dialogo d2({
        u8"[¿Cómo puede que el forastero la entienda? Vuelve a hacer los gestos, esta vez más ob-",
        u8"vios. Apunta agarra el cesto de yucas, intenta levantarlo, pero es muy pesado.]",
        u8"DOÑA ROSA: Yucas... Llevar... Casa...",
        }, opciones0_1);

    Dialogo d3({
        u8"DONA ROSA: Gracias, hijo. Sé que no eres de aquí, y que no entiendes lo que hablo.  No",
        u8"hay problema. Yo te enseñaré...",
        u8"[La anciana entra a su cabaña y saca algunos objetos del día al día,  y empieza a nom-",
        u8"|brarlos. Luego, apunta al horizonte y empieza a categorizar.  Agua.  Bosque.  Planta.",
        u8"|Niño. Aldea... Luego empieza a actuar. Camina. Hace como que prepara. Como que habla]",
        }, 3, false);

    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);

    NPCInteractuable rosa(u8"Rosa", {
        {" ", u8"m", " ",},
        {" ", u8"O", u8"ɔ",},
        {"/", u8"J", ">",},
        {"<", u8"|", " ",},
        }, 88, 10, arbl0);

    return rosa;
}

NPCInteractuable setupNINivel1Mapa2Tomas() {
    std::vector<Opcion> opciones0 = {
        {u8"[Sentarse a su lado, manteniendo silencio]", {2,2,0}, 1},
        {u8"Buenos días, Abuelo... ¿Qué es lo que observa?", {0,0,0}, 2},
    };

    Dialogo d0({
        u8"[El anciano descansa en la hierba, bajo el umbral de un árbol. Mira fijamente al hori-",
        u8"zonte,  como si  estuviese esperando  algo.  ¿A qué?...  Eso tengo que averiguarlo...]",
        }, opciones0);

    std::vector<Opcion> opciones1 = {
        {u8"[Tomar el tabaco y fumarlo a su lado]", {3,3,3}, 3},
        {u8"¿Qué es lo que observas, Abuelo?", {0,0,0}, 2},
    };

    Dialogo d1({
        u8"[Me siento junto al anciano. Él no se mueve, ni gira la cabeza para mirarme.   Pasa el",
        u8"tiempo. El silencio se vuelve espeso, luego cómo. Oigo el canto de la selva, expresado",
        u8"en sus animales, en el fluir del agua, en la brisa soplando contra la vegetación]",
        u8"[De pronto, el anciano saca  una  bolsa de tabaco seco.  Lo enciende.  Y me lo ofrece]",
        u8"DON TOMAS: Sheri. Para el silencio. El silencio es la primera ñaantsi."
        }, opciones1);

    Dialogo d2({
        u8"[El anciano gira la  cabeza  por  un  momento y me observa con un gesto de curiosidad]",
        u8"DON TOMAS: Ah... español. Extraño timpinare, ¿Qué buscas? ¿Ruido? Los extraños siempre",
        u8"hacen ruido, y nada más.",
        u8"[Niega con la cabeza y vuelve  a mirar al  horizonte.  Las palabras no son bienvenidas",
        u8"aquí]"
        });

    Dialogo d3({
        u8"[Tomo el tabaco, y con ayuda del encendedor que guardo en los bolsillos, empiezo a fu-",
        u8"marlo. Puff... Es bienvenido en este extraño contexto. El anciano parece comprender mi",
        u8"peculiar actitud]",
        u8"DON TOMAS: Mis ojos ya no ven como antes.   Pero mis ojos de adentro... esos ven mejor",
        u8"que antes.  Veo a mis ancestros navegando...  Veo sus rostros.  Y  siento  sus  almas.",
        u8"                              [Presione E para continuar]                             "
        }, 4);

    Dialogo d4({
        u8"DON TOMAS: No sé leer palabras, pero sé leer a la naturaleza. Leo a las estrellas. Leo",
        u8"al río, y a los árboles, y ellos me dicen que están sufriendo. Es por esos hombres que",
        u8"han llegado y nos han robado nuestras tierras.  La madre Kipatsi llora, y oigo sus la-",
        u8"mentos. Fue en la quebrada Yonkiri donde todo empezó. Nos amenazaron. Nos golpearon. Y",
        u8"cuando intentamos defendernos, ellos trajeron más extraños que clamaban tener una 'de-",
        u8"nuncia'. Puedes verlo por ti mismo. El río, y la tierra, al borde de la muerte..."
        }, 4);

    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);

    NPCInteractuable tomas(u8"Tomas", {
        {" ", "x", " "},
        {"<", "O", " "},
        {"<", "I", "\\"},
        {" ", "|", ">"},
        }, 41, 17, arbl0);

    return tomas;
}

NPCInteractuable setupNINivel1Mapa3Elena() {
    std::vector<Opcion> opciones0 = {
        {u8"Soy periodista. De Crónica Viva. ¿Es usted la maestra?", {2,0,0}, 1},
        {u8"¿Dos forasteros? ¿En seis meses?", {2,0,0}, 2},
    };

    Dialogo d0({
        u8"[A las afueras de lo que  parece ser una escuela,  hay una mujer de aspecto peculiar.",
        u8"Foránea. Evidentemente, no es de la aldea. Está observando la escuela a través de las",
        u8"ventanas, esperando a que los niños lleguen. Es la maestra.  Al verte, gira la cabeza",
        u8"y sonríe con sorpresa]",
        u8"ELENA: ¿Otro forastero? ¡Dos en seis meses! Esto es un récord."
        }, opciones0);

    std::vector<Opcion> opciones1 = {
        {u8"¿La historia es diferente? Cuéntame más [MIN 25 DE CONFIANZA]", {2,2,0}, 3, 30},
    };

    Dialogo d1({
        u8"ELENA: Elena  Cárdenas.  Oficialmente,  'docente bilingüe  interina'.  Oficiosamente,",
        u8"'la loca que se vino a la selva'...  ¿Y con que periodista, eh?   ¿Y de Crónica Viva?",
        u8"Recuerdo haber leído algunos reportajes. Muy bien hechos, la verdad.  Pero... aquí la",
        u8"historia es diferente. Aunque me sorprende que se hayan tomado la molestia en  enviar",
        u8"a alguien..."
        }, opciones1);

    Dialogo d2({
        u8"ELENA: ¿Dos forasteros? Uno es usted.  Y el otro soy yo. Jaja... llegué en marzo. Pa-",
        u8"rece poco, pero aquí cada día es... intenso.    Dígame, ¿Ya lo trataron mal? No se lo",
        u8"tome a personal, aquí tratan mal a todo el mund al principio.      Es el protocolo de",
        u8"bienvenida.    Aunque, sinceramente, no se los puedo reprochar, viendo todo lo que ha",
        u8"pasado recientemente..."
        }, opciones1);

    std::vector<Opcion> opciones2 = {
        {u8"¿Desertaron? ¿Para ir a trabajar?", {5,8,0}, 4},
    };

    Dialogo d3({
        u8"ELENA: Mire, le cuento un poco de mi historia. Llegué aquí para un programa piloto de",
        u8"educación bilingüe.    Castellano y asháninka.     Los niños aprenden en dos idiomas.",
        u8"Pero en seis meses, he presenciado en primera fila la realidad del pueblo.  Un salón,",
        u8"por lo general, tiene quince alumnos. Quince. En una comunidad de ciento veinte fami-",
        u8"lias. Antes, me cuentan, el promedio era treinta. ¿Sabe dónde están los otros?"
        }, opciones2);

    Dialogo d4({
        u8"ELENA: Los más grandes, en las talas.  Les pagan diez soles al día por cargar troncos",
        u8"o talar árboles. Diez soles al día. Trescientos al mes si trabajan todos los días.   ",
        u8"Los más chicos no se escapan. Ayudan en la chacra o en la pesca, pues tienen que ayu-",
        u8"dar a sus padres, pues las ganancias ya no son como antes.   O simplemente, están en-",
        u8"fermos. Vómitos. Diarrea. El agua de río está podrida y nadie hace nada. Y los demás,",
        u8"emigraron. A donde sea. Pues aquí ya no hay futuro...                                ",
        u8"                             [Presione E para continuar]                             ",
        }, 5);

    Dialogo d5({
        u8"ELENA: Mire, le voy a dar algo que espero que le sea útil. Es mi diario de estos seis",
        u8"meses. Sí, fui tan intrépida como para jugar a ser periodista cuando solamente soy u-",
        u8"na maestra... ¿pero que más pude haber hecho? Hay notas, fotos, nombres, reportes es-",
        u8"critos. Puse todo lo que oía, lo que averiguaba.  Quizás no sea mucho.  Quizás no sea",
        u8"suficiente, pero es algo. Y usted tiene un millón de chances más que yo de hacer algo",
        u8"que de verdad cambie el rumbo de este pueblo.",
        }, 5);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);
    arbl0.agregarDialogo(d5, 0);

    NPCInteractuable elena(u8"elena", {
        {"_", "m", "_"},
        {" ", "O", "?"},
        {"<", "J", ">"},
        {"/", "|", " "},
        }, 62, 11, arbl0);

    return elena;
}

NPCInteractuable setupNINivel1Mapa3Silvia() {
    std::vector<Opcion> opciones0 = {
        {u8"¿Le diste agua de río? [MIN. CON. LENGUA: 15]", {0,5,0}, 1, 5, 15},
        {u8"Tu hijo está enfermo. ¿Puedo verlo? [MIN. CON. LENGUA: 10]", {2,5,5}, 2, 5, 10},
        {u8"Eh...", {0,0,0}, 0},
    };

    Dialogo d0({
        u8"[Una mujer, joven, descansa posada contra la pared de una cabaña. Tiene una expresión",
        u8"|perdida.  Está cargando a un bebé evidentemente enfermo en brazos.    Al verte, mira",
        u8"|con desconfianza, pero el llanto del bebé puede más. Habla atropelladamente.]",
        u8"SILVIA: Mi hijo está enfermo... por beber esa agua enferma del río...",
        }, opciones0, false);

    std::vector<Opcion> opciones1 = {
        {u8"Prometo buscar ayuda", {6,3,5}, 3},
        {u8"Llévaselo a la profesora Elena. Y no vuelvas a darle agua del río...", {1,3,3}, 4},
    };

    Dialogo d1({
        u8"[Asiente, con lágrimas en los ojos. El bebé toce débilmente, como un maullido]",
        u8"SILVIA:Sí... no había otra.  La lluvia no viene. El pozo estaba seco. Solo ha-",
        u8"bía el río... Y el río está enfermo. Enfermo... Mamá CLARA le dió hierbas. Pe-",
        u8"ro no es suficiente. Necesita la POSTA. Pero está lejos, muy lejos... y mi ma-",
        u8"rido está en la quebrada, trabajando para los MADEREROS...",
        }, opciones1, false);

    Dialogo d2({
        u8"[Silvia duda. Pero tras un momento de reflexión, asiente, y me entrega al bebé.  Pue-",
        u8"do ver su cuerpecito de cerca: en su piel hay un sarpullido rojizo.    Sus ojos están",
        u8"hundidos. Respira con dificultad.]",
        u8"SILVIA: Nija... Katsimari nija...",
        });

    Dialogo d3({
        u8"[Su mirada es una mezcla extraña de esperanza y entrenado escepticismo]",
        u8"SILVIA: No... Eso dijeron los demás. Todos prometen ayudar y nadie hace nada. Pero...",
        u8"vi que ayudaste a los demás. Creeré que eres diferente. Espero no equivocarme...",
        }, 3, false);

    Dialogo d4({
        u8"[Silvia niega con la cabeza, y mese al bebé en brazos]",
        u8"SILVIA: No, Elena ya vino.   Me dio pastillas para el bebé.   Pero la diarrea vuelve.",
        u8"Siempre vuelve. Mientras el agua esté mala, el bebé estará malo...",
        }, 4, false);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);

    NPCInteractuable silvia(u8"silvia", {
        {" ", "_", "_", " "},
        {"¿", "O", " ", " "},
        {"<", "L", "w", ">"},
        {" ", "|", ">", " "},
        }, 13, 17, arbl0);

    return silvia;
}

NPCInteractuable setupNINivel1Mapa3Clara() {
    std::vector<Opcion> opciones0 = {
        {u8"Buenos días, ¿Es usted la curandera del pueblo?", {0,0,0}, 1},
    };

    Dialogo d0({
        u8"[Mamá Clara está moliendo hojas secas en un mortero de piedra.   El aire alrededor de",
        u8"su casa huele a hojas secas y a humo dulce.    Al verme, deja el mortero y levanta la",
        u8"cabeza con ojos  pequeños  pero  increíblemente  agudos.  No dice nada. Solo espera.]",
        }, opciones0);

    std::vector<Opcion> opciones1 = {
        {u8"Curandera. Es la palabra más adecuada.", {7,0,7}, 2},
        {u8"¿Mamá Clara? Si no me equivoco, así la llaman en el pueblo", {4,0,7}, 3},
        {u8"No lo sé. No la conozco bien.", {5,0,7}, 4},
    };

    Dialogo d1({
        u8"MAMÁ CLARA: Curandera. Bruja. Vieja. Así me llaman.  ¿Cómo me llamarás tú, fo-",
        u8"rastero? [Me escruta con la mirada. No es una pregunta retórica]",
        }, opciones1);

    Dialogo d2({
        u8"MAMÁ CLARA: Curandera...  Buena palabra.  Es la más justa.   Mi hermana Rosa dijo que",
        u8"eras trabajadores, y no un 'periodista' más. Ven, siéntate. Tengo algo para ti.",
        u8"                             [Presione E para continuar]                             ",
        }, 5);

    Dialogo d3({
        u8"MAMÁ CLARA: Mamá Clara... así me llaman los que me respetan.  ¿Tú me respetas, perio-",
        u8"dista? ¿O tan sólo buscas 'información'?     [La última palabra lo dice con sarcasmo]",
        u8"                             [Presione E para continuar]                             ",
        }, 5);

    Dialogo d4({
        u8"MAMÁ CLARA: No lo sabes... Honesto. Eso es raro para los de tu tipo. A la mayoría les",
        u8"da miedo decir 'no sé' y tienen que fingir conocerlo todo. Anda, siéntate, no muerdo,",
        u8"solo curo.",
        u8"                             [Presione E para continuar]                             ",
        }, 5);

    Dialogo d5({
        u8"MAMÁ CLARA: Las plantas tienen alma.  La naturaleza, en sí, es un todo.   Nosotros no",
        u8"somos superiores a los animales, o a las plantas. Dependemos de ellas. Y ellas depen-",
        u8"den de nosotros. Nuestro pueblo nació de la comunión del hombre con la tierra, Kipat-",
        u8"si. Cuando cosechamos, o pescamos, le pedimos permiso a la tierra. Cuando alguien en-",
        u8"enferma, le pedimos permiso para que nos cure. Esto es así. Y por siglos, siempre  ha",
        u8"sido así... hasta que, recientemente, algo muy grave cambió...",
        u8"                             [Presione E para continuar]                             ",
        }, 6);

    Dialogo d6({
        u8"MAMÁ CLARA: Los hombres del monte, a los que les llamamos 'Los Mudo',  llegaro en ca-",
        u8"ravanas y grandes botes. Se establecieron cerca a la Quebrada Yonkiri, nuestro puerto",
        u8"pesquero por décadas. Y en solo meses... el río lloraba de dolor. Los peces aparecían",
        u8"panza arriba, y colores extraños flotaban como espuma. Y nuestros niños se enfermaban",
        u8"por doquier. Yo lo sé, por que yo era los que los trataba.   Pero, ante tanta maldad,",
        u8"las plantas no eran suficientes, y muchos de ellos murieron...",
        u8"                             [Presione E para continuar]                             ",
        }, 7);

    Dialogo d7({
        u8"MAMÁ CLARA: Ten, periodista, este registro.    Elena lo hizo, pues yo no sé escribir.",
        u8"Están todos los nombres de los que murieron, junto a sus datos, y sus fotos.   Perio-",
        u8"dista, si de verdad dices ser diferente, oye el llamado de la naturaleza. Kipatsi es-",
        u8"tá furiosa ante tan salvaje agresión, y quizás, ante nuestra inacción.",
        }, 7);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);
    arbl0.agregarDialogo(d5, 0);
    arbl0.agregarDialogo(d6, 0);
    arbl0.agregarDialogo(d7, 0);

    NPCInteractuable clara(u8"clara", {
        {" ", u8"¥", " ", " ",},
        {"c", "O", " ", " ", },
        {"<", "J", "U", ">", },
        {" ", "|", ">", " ", },
        }, 83, 10, arbl0);

    return clara;
}

NPCInteractuable setupNINivel1Mapa4Maza() {
    std::vector<Opcion> opciones0 = {
        {u8"Sí, soy periodista. ¿A poco a que me estabas esperando, eh?", {0,0,0}, 1},
        {u8"No tengo por qué decirte quien soy", {0,0,0}, 2},
    };

    Dialogo d0({
        u8"[Don Maza está organizando su mercancía, volviéndola a ordenar por enémisa vez la ho-",
        u8"ra. Sin embargo, al levantar la mirada, logra observarme, y abre ambos brazos]",
        u8"MAZA: ¡Eh, forastero! ¿Otro de ustedes?  ¡Este lugar se está volviendo un centro tu-",
        u8"rístico! Pero vamos, ¿Quién eres? No serás de la ONG, ¿no?    No... eres periodista.",
        u8"Sí, lo eres. ¿Le atiné, eh?"
        }, opciones0);

    Dialogo d1({
        u8"MAZA: ¡Y quizás que sí! Obviamente, no eres de una ONG.   Ellos vienen con chalecos,",
        u8"botas nuevas y balsas llenas de comida que se agotan en dos semanas.   En cambio, tu",
        u8"vienes con la ropa arrugada y con una cara ...    ¡Cómo si hubieses visto al diablo!",
        u8"Además, un pajarito me contó que venías. No es un secreto, en realidad.  Los del mu-",
        u8"elle no saben guardar secretos.",
        u8"                             [Presione E para continuar]                             ",
        }, 3);

    Dialogo d2({
        u8"MAZA: ¿Un poco serio, periodista? No, lo siento, pero no hace falta que pregunte. Tu",
        u8"apariencia no engaña ni a un infante. Y pues, ¿Quién más podría ser?  Los forasteros",
        u8"que no traen algún tipo de bien consigo son extremadamente raros. Los que vienen son",
        u8"comerciantes. Buscan un dinero extra. Y tú... tú también vienes en búsqueda de algo.",
        u8"Quizás no de dinero, pero de información. Así es cómo funciona el mundo.",
        u8"                             [Presione E para continuar]                             ",
        }, 5);

    std::vector<Opcion> opciones1 = {
        {u8"¿Quieres que te pague para que hables? Va. Así es como funciona el mundo real.", {-3,0,5}, 4},
        {u8"¿Un incentivo? Lo siento, no he caído tan bajo como para dar sobornos.", {3,0,0}, 5},
    };

    Dialogo d3({
        u8"MAZA: Ven, ven, acércate, no tengas miedo... [Susurrando] Soy zorro viejo, y he reco-",
        u8"rrido este río por más de veinte años.   ¡Y nunca rechazo una buena chela con alguien",
        u8"más! Por eso, conozco cosas. Mucho más de las que Wilmer y Evaristo saben.  Ellos mi-",
        u8"ran al pueblo, y yo miro el río. Y en el río pasan cosas de noche. Mira, voy al grano",
        u8"Un incentivo no vendría mal.  Yo busco mi ganancia.  Tú información.   Ambos ganamos."
        }, opciones1);

    Dialogo d4({
        u8"MAZA: ¡Ahora sí hablamos! 50 soles. Es barato para todo lo que vas a conseguir.",
        u8"Dato uno: Los madereros se mueven de noche. Entres las doce y las tres. Es cuando pa-",
        u8"san la madera —y otras mercancías— río abajo.",
        u8"Dato dos: Hay un tipo en la quebrada. No es maderero. Es químico.  Mezcla cosas. Pre-",
        u8"aquellos extraños bidones que entierran.",
        u8"Dato tres: La próxima semana, llega un cargamento. Todos están nerviosos. Incluso los",
        u8"Mudo. ¿Qué es? No lo sé. ¡Y mejor que sea así!"
        }, 4);

    Dialogo d5({
        u8"MAZA: Ah... siempre tan aguafiestas, periodista. ¿Mateo López, no? Leí algunos de tus",
        u8"artículos. Son... interesantes. Pero siento que les falta un poco de sazón.  Un sabor",
        u8"de la susodicha 'verdad' que tanto defiendas, que te impulsaría a la fama y  le daría",
        u8"un empujoncito al pueblo.  ¡Pero no me sorprende que le falte tanta sazón si eres tan",
        u8"aburrido y puritano! No hay problema. Tendrás que conseguir información a la antigua,",
        u8"preguntando. Y ya sabes como funciona eso aquí.",
        }, 5);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);
    arbl0.agregarDialogo(d4, 0);
    arbl0.agregarDialogo(d5, 0);

    NPCInteractuable maza(u8"maza", {
        {"_", "m", "_"},
        {" ", "Q", " "},
        {"<", "U", ">"},
        {" ", "|", ">"},
        }, 13, 9, arbl0);

    return maza;
}

NPCInteractuable setupNINivel1Mapa4Jeremias() {
    std::vector<Opcion> opciones0 = {
        {u8"Sí, soy de fiar.", {1,0,0}, 1},
        {u8"Eso espero.", {0,0,0}, 1},
    };

    Dialogo d0({
        u8"[Jeremías está cortando los tablones que, por lo que parece, se utilizarán para cons",
        u8"truir un bote. Parece tener experiencia con la madera. Al acercarme, se paraliza,  y",
        u8"deja de hacer lo que está haciendo. Duda por un momento. Luego se acerca]",
        u8"JEREMIAS: Ey, periodista.   ¿Eres alguien de fiar? Wilmer dijo que probablemente sí.",
        }, opciones0);

    std::vector<Opcion> opciones1 = {
        {u8"Cuéntamelo. Estás en discresión conmigo.", {3,0,6}, 2},
        {u8"¿Por qué me lo dices a mí, el forastero, y no a tu comunidad?", {0,0,6}, 3},
    };

    Dialogo d1({
        u8"JEREMIAS: Espero que sí. Por que si no, estoy muerto.  Mira, yo trabajo para los ma-",
        u8"dereros. Allá en la quebrada, ocasionalmente. No me gusta.  Pero mi hermana está en-",
        u8"ferma y mi mamá no puede trabajar. Y yo tengo que ayudar en casa, sea como sea.",
        u8"Pero... hay cosas que ellos hacen que no están bien.  Cosas que ni siquiera Wilmer o",
        u8"cualquiera del pueblo saben.",
        }, opciones1);

    Dialogo d2({
        u8"JEREMIAS: Tienen bidones enterrados por la quebrada.    No solo trabajan con madera.",
        u8"Es de un negocio 'extra' del que todos hablan pero que solo los altos rangos conocen",
        u8"los detalles. También tienen químicos. No sé que son, pero son peligrosos. Un traba-",
        u8"jador abrió unos y se quemó las manos.   Estos están en un claro, detrás de la ceiba",
        u8"caída. Si vas, ten cuidado. Hay un tipo al que le llaman 'El Químico'. Él es diferen",
        u8"te a los demás. Es malo. Muy malo.",
        }, 2);

    Dialogo d3({
        u8"JEREMIAS: Porque no tengo el coraje para hacerlo. No sabes de la vergüenza que me cau",
        u8"sa tener que estar allí cada maldito día, sabiendo lo que sé. Y aunque pudiera, no se",
        u8"lo diría a nadie. Si se lo digo a Wilmer, él actuará. Y lo van a matar.   La otra vez",
        u8"pegaron, y si no fuese por la intervención de Evaristo y los vecinos, lo hubiesen ma-",
        u8"tado. En cambio, tú... tú puedes hacer un gran cambio.  Exponerlos.  Y ni aunque ame-",
        u8"dranten a medio mundo se saldrán con la suya."
        }, 2);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);

    NPCInteractuable jeremias(u8"jeremias", {
        {" ,  "},
        {" O n"},
        {"<|L|"},
        {" |> "},
        }, 36, 10, arbl0);

    return jeremias;
}

NPCInteractuable setupNINivel1Mapa4Timoteo() {
    std::vector<Opcion> opciones0 = {
        {u8"¿Qué es lo que le pasa al río?", {3,1,5}, 1},
        {u8"¿Es por esas manchas brillantes y espumosas?", {5,1,5}, 2},
    };

    Dialogo d0({
        u8"[Timoteo, un hombre mayor, de  quizás  más  de 70 años, descansa cerca de la orilla,",
        u8"con su caña de pescar en manos.  Cuando me acerco, no se voltea, pero un sutil movi-",
        u8"miento en su espalda muestra que me ha oído llegar. Habla sin voltearse]",
        u8"TIMOTEO: ¿Sabes cuántos peces saqué hoy? Ninguno. Ayer, nada. La semana pasada, solo",
        u8"uno. Chiquito. Este río era mi despensa. Ahora se volvió mi cementerio."
        }, opciones0);

    Dialogo d1({
        u8"TIMOTEO: Lo han envenenado. Allá, en la quebrada Yonkiri, donde antes nosotros pes-",
        u8"cábamos y teníamos nuestras cabañas.   Ahora que no estamos, han levantado laborato-",
        u8"rios. No sé que hacen, pero todos sus desechos los tiran al río.  Antes se podía be-",
        u8"ber directamente de él. Ahora... mira [Saca un tubo con un líquido espumoso y amari-",
        u8"llento. El olor es horrible. Logro distinguir lo que parece ser el olor a gasolina]",
        u8"                             [Presione E para continuar]                             ",
        }, 3);

    Dialogo d2({
        u8"TIMOTEO: Las viste bien.    La mayoría de forasteros no se contentan con mirar, solo",
        u8"con preguntar. Esas manchas son ácido, quizás gasolina, o algo peor.  Los peces flo-",
        u8"tan panza arriba. Y todo aquel que bebe ese agua, así la hierva, está en riesgo. De-",
        u8"cenas de niños han enfermado por ello. E incluso, algunos murieron. Mis nietos ya no",
        u8"comen peces del río. Tienen miedo.",
        u8"                             [Presione E para continuar]                             ",
        }, 3);

    Dialogo d3({
        u8"TIMOTEO: Mis bisabuelos llegaron aquí, huyendo de los caucheros. La naturaleza los a-",
        u8"cobijo. Y el chamán les dijo: 'Aquí. Esta tierra es kametsa'.  Kametsa significa buen",
        u8"vivir. Y así era antes. Nosotros protegíamos a la naturaleza, y ella nos recompensaba",
        u8"dándonos cobijo y alimento. Pero eso era antes. Le hemos fallado. Está agonizando.  Y",
        u8"nosotros estamos agonizando junto a ella.",
        }, 3);


    ArbolDialogo arbl0;

    arbl0.agregarDialogo(d0, 0);
    arbl0.agregarDialogo(d1, 0);
    arbl0.agregarDialogo(d2, 0);
    arbl0.agregarDialogo(d3, 0);

    NPCInteractuable timoteo(u8"timoteo", {
        {"_", "z", "_", " ", " ", " ",},
        {" ", "G", " ", " ", "/", "|",},
        {"<", "|", "\\", "/", " ", " ",},
        {" ", "|", ">", " ", " ", " ",},
        }, 78, 15, arbl0);

    return timoteo;
}