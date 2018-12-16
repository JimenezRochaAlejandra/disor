require_relative 'Pantalla/controlador_de_interfaz'

Shoes.app title: "CifradorCesar&TIA", width: 750, height: 720 do
  background "#F3F".."#F90"

  stack margin: 7 do
    para "CIFRADO CÉSAR Y CIFRADO POR TRANSPOSICIÓN INVERSA"
  end

  stack margin: 7 do
    border black, strokewidth: 1

    stack(margin: 7) do
      para "Mensaje original:"
      flow do
        @txtEntrada = edit_box width: 600, height: 80
      end
    end
  end

  stack margin: 7 do
    border black, strokewidth: 1
    para "Cifrado César"

    stack(margin: 7) do
      para "Desplazamiento:"
      flow do
        @txtDesplazamientoCesar = edit_line width: 300
        @txtDesplazamientoCesar.text = "1"
      end
    end

    stack(margin: 7) do
      para "Texto cifrado:"
      flow do
        @txtCifradoCesar = edit_box width: 600, height: 80
      end
    end
  end

  stack margin: 7 do
    border black, strokewidth: 1
    para "Cifrado por transposición inversa"
    stack(margin: 7) do
      flow do
        para "Texto cifrado:"
        @txtCifradoTransposicionInversa = edit_box width: 600, height: 80
      end
    end
  end

  stack margin: 7 do
    border black, strokewidth: 1
    para "Cifrado por transposición inversa por grupos"

    stack(margin: 7) do
      para "Tamaño de los grupos:"
      flow do
        @txtGroupSize = edit_line width: 300
        @txtGroupSize.text = "2"
      end
    end

    stack(margin: 7) do
      para "Texto cifrado:"
      flow do
        @txtCifradoTransposicionInversaPorGrupos = edit_box width: 600, height: 80
      end
    end
  end


  objControlador = ControladorDeInterfaz.new(@txtEntrada, @txtCifradoCesar, @txtDesplazamientoCesar, @txtCifradoTransposicionInversa, @txtCifradoTransposicionInversaPorGrupos, @txtGroupSize)

end