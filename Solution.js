
/**
 * @param {number[]} distance
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function (distance, speed) {
    this.DISTANCE_RANGE = [1, Math.pow(10, 5)];
    this.SPEED_RANGE = [1, Math.pow(10, 5)];
    this.MAX_TIME_TO_REACH_THE_CITY = Math.ceil(DISTANCE_RANGE[1] / SPEED_RANGE[0]);
    this.numberOfMonstersToReachTheCityAtTimePoint = new Array(MAX_TIME_TO_REACH_THE_CITY + 1).fill(0);

    const totalNumberOfMonsters = distance.length;

    initializeArray_numberOfMonstersToReachTheCityAtTimePoint(distance, speed);
    return findMaxNumberOfEliminatedMonsters(totalNumberOfMonsters);
};

/**
 * @param {number[]} distance
 * @param {number[]} speed
 * @return {void}
 */
function initializeArray_numberOfMonstersToReachTheCityAtTimePoint(distance, speed) {
    for (let i = 0; i < distance.length; ++i) {
        ++this.numberOfMonstersToReachTheCityAtTimePoint[ Math.ceil(distance[i] / speed[i])];
    }
}

/**
 * @param {number} totalNumberOfMonsters
 * @return {number}
 */
function findMaxNumberOfEliminatedMonsters(totalNumberOfMonsters) {
    let eliminatedMonsters = 1;

    for (let time = 0; time < this.numberOfMonstersToReachTheCityAtTimePoint.length; ++time) {

        this.numberOfMonstersToReachTheCityAtTimePoint[time] += time > 0 ? this.numberOfMonstersToReachTheCityAtTimePoint[time - 1] : 0;

        //can eliminate monsters only at a distance
        if (eliminatedMonsters <= this.numberOfMonstersToReachTheCityAtTimePoint[time]) {
            --eliminatedMonsters;
            break;
        }
        if (eliminatedMonsters === totalNumberOfMonsters) {
            break;
        }
        ++eliminatedMonsters;
    }
    return eliminatedMonsters;
}
