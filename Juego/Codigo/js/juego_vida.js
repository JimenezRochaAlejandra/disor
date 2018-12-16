var Universo = function(){
    var estadoDelJuego = {
        jugando: false,
        celulasVivas: {
            anterior: [],
            actual: []
        }
    };
    var tamanioDeCelula = 5;
    var btnRandom   = document.querySelector('#random');
    var btnPlay     = document.querySelector('#start');
    var btnStop     = document.querySelector('#stop');
    var btnClear    = document.querySelector('#clear');
    var vecindario  = document.querySelector('#vecindario');
    var contexto    = vecindario.getContext('2d');
    
    vecindario.style.backgroundColor = '#000';
    contexto.fillStyle = '#fff';
    
    vecindario.addEventListener('click', function(e) {
        if (estadoDelJuego.jugando) {
            return;
        }
        var pos = obtenerPosicion(e, this);
        if (!!revisarEstadoDeCelula(pos)) {
            limpiarCelula(pos);
        } else {
            pintarCelula(pos);
        }
    });

    btnRandom.addEventListener('click', function(e) {
        var tamanioDelVecindario = obtenerTamanioDelVecindario();
        if (estadoDelJuego.jugando) {
            return;
        }
        var cellsToCreate = Math.floor((Math.random() * tamanioDelVecindario.w) + 1) + 1;
        var dynamicCell = {x: 0, y:0};
        var randomBase = {
            x: Math.ceil(tamanioDelVecindario.w / tamanioDeCelula),
            y: Math.ceil(tamanioDelVecindario.h / tamanioDeCelula)
        };
        while (cellsToCreate--) {
            dynamicCell.x = Math.floor(Math.random() * randomBase.x) * tamanioDeCelula;
            dynamicCell.y = Math.floor(Math.random() * randomBase.y) * tamanioDeCelula;
            pintarCelula(dynamicCell);
        }
    });
    btnPlay.addEventListener('click', function(e) {
        if (estadoDelJuego.jugando) {
            return;
        }
        estadoDelJuego.process = setTimeout(function run() {
            play();
            if (estadoDelJuego.celulasVivas.anterior.length < 1) {
                estadoDelJuego.jugando = false;
                return;
            }
            estadoDelJuego.jugando = true;
            estadoDelJuego.process = setTimeout(run, 50);
        }, 50);
    });
    btnStop.addEventListener('click', function(e) {
        if (estadoDelJuego.jugando) {
            clearTimeout(estadoDelJuego.process);
            estadoDelJuego.jugando = false;
        }
    });
    btnClear.addEventListener('click', function(e) {
        var tamanioDelVecindario = obtenerTamanioDelVecindario();
        if (estadoDelJuego.jugando) {
            return;
        }
        contexto.clearRect(0, 0, tamanioDelVecindario.w, tamanioDelVecindario.h);
        estadoDelJuego.celulasVivas.anterior = [];
        estadoDelJuego.celulasVivas.actual = [];
    });
    function play() {
        estadoDelJuego.celulasVivas.anterior = estadoDelJuego.celulasVivas.actual.slice();
        var i, posCellToCheck, s;
        var cellsToCheck = estadoDelJuego.celulasVivas.anterior.slice();
        for (i = 0, s = estadoDelJuego.celulasVivas.anterior.length; i < s; i++) {
            cellsToCheck = cellsToCheck.concat(
                obtenerCoordenadasDeVecinos(
                    strToPos(estadoDelJuego.celulasVivas.anterior[i])
                ).filter(function(v) {
                    return cellsToCheck.indexOf(v) < 0;
                })
            );
        }
        for (i = 0, s = cellsToCheck.length; i < s; i++) {
            posCellToCheck = strToPos(cellsToCheck[i]);
            var newStateOfCell = determinarEstadoDeLaCelula(posCellToCheck);
            if (typeof newStateOfCell === 'undefined') {
                continue;
            }
            if (newStateOfCell > 0) {
                pintarCelula(posCellToCheck);
            } else {
                limpiarCelula(posCellToCheck);
            }
        }
    }
    function obtenerPosicion(e, elem) {
        var pos = elem.getBoundingClientRect();
        return {
            x: Math.floor((e.clientX - pos.left) / tamanioDeCelula) * tamanioDeCelula,
            y: Math.floor((e.clientY - pos.top) / tamanioDeCelula) * tamanioDeCelula
        };
    }
    function pintarCelula(pos) {
        var strPos = posToStr(pos);
        contexto.fillRect(pos.x, pos.y, tamanioDeCelula, tamanioDeCelula);
        if (estadoDelJuego.celulasVivas.actual.indexOf(strPos) < 0) {
            estadoDelJuego.celulasVivas.actual.push(strPos);
        }
    }
    function limpiarCelula(pos) {
        contexto.clearRect(pos.x, pos.y, tamanioDeCelula, tamanioDeCelula);
        estadoDelJuego.celulasVivas.actual.splice(
            estadoDelJuego.celulasVivas.actual.indexOf(posToStr(pos)),
            1
        );
    }
    function determinarEstadoDeLaCelula(pos) {
        var neighborsAlive = obtenerVecinosVivos(
            obtenerCoordenadasDeVecinos(pos)
        );
        var stateOfCell = revisarEstadoAnteriorDeCelula(pos);
        if (stateOfCell > 0) {
            if (neighborsAlive < 2 || neighborsAlive > 3) {
                return 0;
            }
        }
        if (stateOfCell === 0) {
            if (neighborsAlive === 3) {
                return 1;
            }
        }
    }
    function revisarEstadoDeCelula(pos) {
        if (estadoDelJuego.celulasVivas.actual.indexOf(posToStr(pos)) > -1) {
            return 1;
        }
        return 0;
    }
    function revisarEstadoAnteriorDeCelula(pos, str) {
        if (str === true) {
            if (estadoDelJuego.celulasVivas.anterior.indexOf(pos) > -1) {
                return 1;
            }
            return 0;
        }
        if (estadoDelJuego.celulasVivas.anterior.indexOf(posToStr(pos)) > -1) {
            return 1;
        }
        return 0;
    }
    function obtenerCoordenadasDeVecinos(pos) {
        var tamanioDelVecindario = obtenerTamanioDelVecindario();
        var getPosNeighbor = function(x, y, neighbor) {
            return ((neighbor[0] * tamanioDeCelula) + x) + ',' + ((neighbor[1] * tamanioDeCelula) + y);
        };
        var neighbors =[
            [-1, -1],
            [0, -1],
            [1, -1],
            [-1, 0],
            [1, 0],
            [-1, 1],
            [0, 1],
            [1, 1]
        ];
        var i = neighbors.length;
        while (i--) {
            neighbors[i] = getPosNeighbor(pos.x, pos.y, neighbors[i]);
        }
        return neighbors;
    }
    function obtenerVecinosVivos(coords) {
        return coords.filter(function(v) {
            return revisarEstadoAnteriorDeCelula(v, true) > 0;
        }).length;
    }
    function obtenerTamanioDelVecindario() {
        return {
            w: vecindario.width,
            h: vecindario.height
        };
    }
    function posToStr(pos) {
        return pos.x + ',' + pos.y;
    }
    function strToPos(pos) {
        var arrPos = pos.split(',');
        return {
            x: parseInt(arrPos[0]),
            y: parseInt(arrPos[1])
        };
    }
}();