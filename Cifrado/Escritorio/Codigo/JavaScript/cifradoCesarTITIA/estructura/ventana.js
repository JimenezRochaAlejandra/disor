//var e = require("./elementos.js");
//const remote = require("electron").remote;
e.addToBody(e.creaDiv("mensaje"));
e.addToElement("mensaje",e.creaLabel("Mensaje: "));
e.addToElement("mensaje",e.creaTextArea("mensajeTA",8,40));

e.addToBody(e.creaDiv("Fieldsets"));
e.addToElement("Fieldsets",e.creaFielset("Cesar","Cifrado César"));
e.addToElement("Cesar",e.creaDiv("desplazamiento"));
e.addToElement("Cesar",e.creaDiv("mensajeCifrado"));
e.addToElement("desplazamiento",e.creaLabel("Desplazamiento: "));
e.addToElement("desplazamiento",e.creaInputText("desplazamientoIT"));
e.addToElement("mensajeCifrado",e.creaLabel("Mensaje cifrado:"));
e.addToElement("mensajeCifrado",e.creaTextArea("mensajeCifradoTA",8,40));

e.addToElement("Fieldsets",e.creaFielset("trasposicion","Cifrado por transposición"));
e.addToElement("trasposicion",e.creaDiv("mensajeCifrado2"));
e.addToElement("mensajeCifrado2",e.creaLabel("Mensaje cifrado: "));
e.addToElement("mensajeCifrado2",e.creaTextArea("mensajeCifradoTA2",8,40));


e.addToElement("Fieldsets",e.creaFielset("Tia","Trasposicion inversa agrupada"));
e.addToElement("Tia",e.creaDiv("agrupacion"));
e.addToElement("Tia",e.creaDiv("mensajeCifrado3"));
e.addToElement("agrupacion",e.creaLabel("Número de grupos: "));
e.addToElement("agrupacion",e.creaInputText("agrupacionIT"));
e.addToElement("mensajeCifrado3",e.creaLabel("Mensaje cifrado: "));
e.addToElement("mensajeCifrado3",e.creaTextArea("mensajeCifradoTA3",8,40));







/*let button = document.createElement("button");
button.textContent = "hola";
//document.body.appendChild(button);
e.addToBody(button);
e.addToBody(e.creaBoton("Boton","Cifrar"));
//e.addToElement("boton",e.creaBoton("Boton","Cifrar");
e.hola();*/
