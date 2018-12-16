require_relative '../Texto/texto_cifrado'
require_relative '../Texto/texto_plano'
require_relative '../CifradoCesar/alfabeto'
require_relative '../CifradoCesar/cifrador_cesar'
require_relative '../TransposicionInversa/cifrador_transposicion_inversa'
require_relative '../TransposicionInversaPorGrupos/cifrador_transposicion_inversa_por_grupos'

class ControladorDeInterfaz

  @@objTextoPlano
  @@objTextoCifrado
  @@objAlfabeto
  @@textBoxMensajeOriginal
  @@textBoxCesar
  @@numberCesar
  @@textBoxCifradoInverso
  @@textBoxCifradoInversoPorGrupos
  @@numberCifradoInversoPorGrupos

  def initialize(textBoxMensajeOriginal, textBoxCesar, numberCesar, textBoxCifradoInverso, textBoxCifradoInversoPorGrupos, numberCifradoInversoPorGrupos)
    @@objTextoPlano                   = TextoPlano.new
    @@objTextoCifrado                 = TextoCifrado.new
    @@objAlfabeto                     = Alfabeto.new
    @@textBoxMensajeOriginal          = textBoxMensajeOriginal
    @@textBoxCesar                    = textBoxCesar
    @@numberCesar                     = numberCesar
    @@textBoxCifradoInverso           = textBoxCifradoInverso
    @@textBoxCifradoInversoPorGrupos  = textBoxCifradoInversoPorGrupos
    @@numberCifradoInversoPorGrupos   = numberCifradoInversoPorGrupos

    eventListener()
  end

  def eventListener
    @@textBoxMensajeOriginal.change() do
      cifrarCesar()
      cifrarTransposicionInversa()
      cifrarTIA()
    end

    @@numberCesar.change() do
      cifrarCesar()
    end

    @@numberCifradoInversoPorGrupos.change() do
      cifrarTIA()
    end
  end

  def cifrarCesar
    @@objTextoPlano.agregarTexto(@@textBoxMensajeOriginal.text())

    objCifrador = CifradorCesar.new(@@objAlfabeto, @@objTextoPlano, @@objTextoCifrado, Integer(@@numberCesar.text()))

    objCifrador.cifrar()

    @@textBoxCesar.text = ""

    @@textBoxCesar.text = @@objTextoCifrado.obtenerTexto()

    @@objTextoPlano.limpiar()
    @@objTextoCifrado.limpiar()
  end

  def cifrarTransposicionInversa
    @@objTextoPlano.agregarTexto(@@textBoxMensajeOriginal.text())

    objCifradoTransposicionInversa = CifradorTransposicionInversa.new(@@objTextoPlano, @@objTextoCifrado)

    objCifradoTransposicionInversa.cifrar()

    @@textBoxCifradoInverso.text = ""

    @@textBoxCifradoInverso.text = @@objTextoCifrado.obtenerTexto()

    @@objTextoPlano.limpiar()
    @@objTextoCifrado.limpiar()
  end

  def cifrarTIA
    @@objTextoPlano.agregarTexto(@@textBoxMensajeOriginal.text())

    objTIA = CifradorTransposicionInversaPorGrupos.new(@@objTextoPlano, @@objTextoCifrado, Integer(@@numberCifradoInversoPorGrupos.text()))

    objTIA.cifrar()

    @@textBoxCifradoInversoPorGrupos.text = ""

    @@textBoxCifradoInversoPorGrupos.text = @@objTextoCifrado.obtenerTexto()

    @@objTextoPlano.limpiar()
    @@objTextoCifrado.limpiar()
  end

end