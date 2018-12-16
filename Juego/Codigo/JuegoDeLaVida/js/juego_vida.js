!function(){
    var stateOfGame = {
        playing: false,
        cellsAlive: {
            previous: [],
            actual: []
        }
    };
    var sizeOfCell = 5;
    var btnRandom = document.querySelector('#random');
    var btnPlay = document.querySelector('#start');
    var btnStop = document.querySelector('#stop');
    var btnClear = document.querySelector('#clear');
    var myCanvas = document.querySelector('#mycanvas');
    var canvasContext = myCanvas.getContext('2d');
    myCanvas.style.backgroundColor = '#000';
    canvasContext.fillStyle = '#fff';
    myCanvas.addEventListener('click', function(e) {
        if (stateOfGame.playing) {
            return;
        }
        var pos = getPos(e, this);
        if (!!getStateOfCell(pos)) {
            clearCell(pos);
        } else {
            drawCell(pos);
        }
    });
    btnRandom.addEventListener('click', function(e) {
        var sizeOfCanvas = getSizeOfCanvas();
        if (stateOfGame.playing) {
            return;
        }
        var cellsToCreate = Math.floor((Math.random() * sizeOfCanvas.w) + 1) + 1;
        var dynamicCell = {x: 0, y:0};
        var randomBase = {
            x: Math.ceil(sizeOfCanvas.w / sizeOfCell),
            y: Math.ceil(sizeOfCanvas.h / sizeOfCell)
        };
        while (cellsToCreate--) {
            dynamicCell.x = Math.floor(Math.random() * randomBase.x) * sizeOfCell;
            dynamicCell.y = Math.floor(Math.random() * randomBase.y) * sizeOfCell;
            drawCell(dynamicCell);
        }
    });
    btnPlay.addEventListener('click', function(e) {
        if (stateOfGame.playing) {
            return;
        }
        stateOfGame.process = setTimeout(function run() {
            play();
            if (stateOfGame.cellsAlive.previous.length < 1) {
                stateOfGame.playing = false;
                return;
            }
            stateOfGame.playing = true;
            stateOfGame.process = setTimeout(run, 50);
        }, 50);
    });
    btnStop.addEventListener('click', function(e) {
        if (stateOfGame.playing) {
            clearTimeout(stateOfGame.process);
            stateOfGame.playing = false;
        }
    });
    btnClear.addEventListener('click', function(e) {
        var sizeOfCanvas = getSizeOfCanvas();
        if (stateOfGame.playing) {
            return;
        }
        canvasContext.clearRect(0, 0, sizeOfCanvas.w, sizeOfCanvas.h);
        stateOfGame.cellsAlive.previous = [];
        stateOfGame.cellsAlive.actual = [];
    });
    function play() {
        stateOfGame.cellsAlive.previous = stateOfGame.cellsAlive.actual.slice();
        var i, posCellToCheck, s;
        var cellsToCheck = stateOfGame.cellsAlive.previous.slice();
        for (i = 0, s = stateOfGame.cellsAlive.previous.length; i < s; i++) {
            cellsToCheck = cellsToCheck.concat(
                getCoordsNeighbors(
                    strToPos(stateOfGame.cellsAlive.previous[i])
                ).filter(function(v) {
                    return cellsToCheck.indexOf(v) < 0;
                })
            );
        }
        for (i = 0, s = cellsToCheck.length; i < s; i++) {
            posCellToCheck = strToPos(cellsToCheck[i]);
            var newStateOfCell = determinateStateOfCell(posCellToCheck);
            if (typeof newStateOfCell === 'undefined') {
                continue;
            }
            if (newStateOfCell > 0) {
                drawCell(posCellToCheck);
            } else {
                clearCell(posCellToCheck);
            }
        }
    }
    function getPos(e, elem) {
        var pos = elem.getBoundingClientRect();
        return {
            x: Math.floor((e.clientX - pos.left) / sizeOfCell) * sizeOfCell,
            y: Math.floor((e.clientY - pos.top) / sizeOfCell) * sizeOfCell
        };
    }
    function drawCell(pos) {
        var strPos = posToStr(pos);
        canvasContext.fillRect(pos.x, pos.y, sizeOfCell, sizeOfCell);
        if (stateOfGame.cellsAlive.actual.indexOf(strPos) < 0) {
            stateOfGame.cellsAlive.actual.push(strPos);
        }
    }
    function clearCell(pos) {
        canvasContext.clearRect(pos.x, pos.y, sizeOfCell, sizeOfCell);
        stateOfGame.cellsAlive.actual.splice(
            stateOfGame.cellsAlive.actual.indexOf(posToStr(pos)),
            1
        );
    }
    function determinateStateOfCell(pos) {
        var neighborsAlive = getNeighborsAlive(
            getCoordsNeighbors(pos)
        );
        var stateOfCell = getPrevStateOfCell(pos);
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
    function getStateOfCell(pos) {
        if (stateOfGame.cellsAlive.actual.indexOf(posToStr(pos)) > -1) {
            return 1;
        }
        return 0;
    }
    function getPrevStateOfCell(pos, str) {
        if (str === true) {
            if (stateOfGame.cellsAlive.previous.indexOf(pos) > -1) {
                return 1;
            }
            return 0;
        }
        if (stateOfGame.cellsAlive.previous.indexOf(posToStr(pos)) > -1) {
            return 1;
        }
        return 0;
    }
    function getCoordsNeighbors(pos) {
        var sizeOfCanvas = getSizeOfCanvas();
        var getPosNeighbor = function(x, y, neighbor) {
            return ((neighbor[0] * sizeOfCell) + x) + ',' + ((neighbor[1] * sizeOfCell) + y);
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
    function getNeighborsAlive(coords) {
        return coords.filter(function(v) {
            return getPrevStateOfCell(v, true) > 0;
        }).length;
    }
    function getSizeOfCanvas() {
        return {
            w: myCanvas.width,
            h: myCanvas.height
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