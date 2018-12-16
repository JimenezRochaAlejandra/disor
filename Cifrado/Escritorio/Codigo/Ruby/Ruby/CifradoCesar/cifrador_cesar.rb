class CifradorCesar

  @@alfabeto
  @@textoPlano
  @@textoCifrado
  @@desplazamiento

  def initialize(alfabeto, textoPlano, textoCifrado, desplazamiento)
    @@alfabeto       = alfabeto
    @@textoPlano     = textoPlano
    @@textoCifrado   = textoCifrado
    @@desplazamiento = desplazamiento
  end

  def cifrar
    index = 0
    while (index < @@textoPlano.longitud())
      if (@@alfabeto.existe?(@@textoPlano.caracterEnIndice(index)))
        @@textoCifrado.agregarTexto(obtenerCaracterDesplazado(@@textoPlano.caracterEnIndice(index)))
      else
        @@textoCifrado.agregarTexto(@@textoPlano.caracterEnIndice(index))
      end
      index += 1
    end
  end

  def obtenerCaracterDesplazado(caracterOriginal)
    if (@@alfabeto.indiceDe(caracterOriginal) + @@desplazamiento >= 0)
      return @@alfabeto.caracterEn((@@alfabeto.indiceDe(caracterOriginal) + @@desplazamiento) % @@alfabeto.longitud())
    elsif ((@@alfabeto.indiceDe(caracterOriginal) + @@desplazamiento) < 0 && (@@alfabeto.indiceDe(caracterOriginal) + @@desplazamiento) % @@alfabeto.longitud() === 0)
      return @@alfabeto.caracterEn(0);
    else
      return @@alfabeto.caracterEn(@@alfabeto.longitud() - ((@@alfabeto.indiceDe(caracterOriginal) + @@desplazamiento) % @@alfabeto.longitud()).abs)
    end
  end

end