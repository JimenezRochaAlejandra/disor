class CifradorTransposicionInversa

  @@textoPlano
  @@textoCifrado

  def initialize(textoPlano, textoCifrado)
    @@textoPlano = textoPlano
    @@textoCifrado = textoCifrado
  end

  def cifrar
    indice = @@textoPlano.longitud()-1
    while indice >= 0
      @@textoCifrado.agregarTexto(@@textoPlano.caracterEnIndice(indice))
      indice -= 1
    end
  end

end