class CifradorTransposicionInversaPorGrupos

  @@textoPlano
  @@textoCifrado
  @@groupSize

  def initialize(textoPlano, textoCifrado, groupSize)
    @@textoPlano    = textoPlano
    @@textoCifrado  = textoCifrado
    @@groupSize     = groupSize
  end


  def cifrar
    indice = 0
    while (@@groupSize > 0 && ((indice + @@groupSize-1) < @@textoPlano.longitud()))
      posicion = indice + @@groupSize-1
      while posicion >= indice
        @@textoCifrado.agregarTexto(@@textoPlano.caracterEnIndice(posicion))
        posicion -= 1
      end
      indice += @@groupSize
    end

    while (indice < @@textoPlano.longitud())
      @@textoCifrado.agregarTexto(@@textoPlano.caracterEnIndice(indice))
      indice += 1
    end
  end

end