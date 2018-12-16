class TextoCifrado

  @@textoCifrado

  def initialize
    @@textoCifrado = ""
  end

  def longitud
    return @@textoCifrado.length
  end

  def caracterEnIndice(indice)
    return @@textoCifrado[indice]
  end

  def agregarTexto(otroTexto)
    @@textoCifrado += otroTexto
  end

  def obtenerTexto
    return @@textoCifrado
  end

  def limpiar
    @@textoCifrado  = ""
  end


end