class TextoPlano

  @@textoPlano

  def initialize
    @@textoPlano = ""
  end

  def longitud
    return @@textoPlano.length
  end

  def caracterEnIndice(indice)
    return @@textoPlano[indice]
  end

  def agregarTexto(otroTexto)
    @@textoPlano += otroTexto
  end

  def obtenerTexto
    return @@textoPlano
  end

  def limpiar
    @@textoPlano  = ""
  end

end