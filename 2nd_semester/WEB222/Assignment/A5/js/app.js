let map;

function updateMap(observations, map) {
  // Clear the current markers on the map (if any)
  map.clear();

  observations.forEach(function (observation) {
    map.addObservation(observation);
  });
}

function updateCard(observations) {
  // Remove any current data from the card
  clearAllCards();

  // Populate the card with all observation data we want to show
  observations.forEach((observation) => {
    buildCardForObservation(observation);
  });
}

function showAll() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();

  // Update the map and card
  updateMap(observations, map);
  updateCard(observations);
  updateCardTitle(`All Species (${observations.length})`);
}

function showOnlyNative() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();
  // Filter out any that aren't native species
  const native = filterOnlyNative(observations);

  // Update the map and card
  updateMap(native, map);
  updateCard(native);
  updateCardTitle(`Only Native Species (${native.length})`);
}

function showOnlyIntroduced() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();
  // Filter out any that aren't introduced species
  const introduced = filterOnlyIntroduced(observations);

  // Update the map and card
  updateMap(introduced, map);
  updateCard(introduced);
  updateCardTitle(`Only Introduced Species (${introduced.length})`);
}

function start() {
  // Create our map object for Seneca's Newnham campus
  map = new SimpleMap("map-container", 43.7955, -79.3496);

  showAll();

  let allSpecies = document.querySelector("#show-all");
  let nativeSpecies = document.querySelector("#show-native");
  let introSpecies = document.querySelector("#show-introduced");

  allSpecies.addEventListener("click", function () {
    showAll();
  });

  nativeSpecies.addEventListener("click", function () {
    showOnlyNative();
  });

  introSpecies.addEventListener("click", function () {
    showOnlyIntroduced();
  });
}

window.addEventListener("load", function (e) {
  console.log(`OK, let's begin!`);
  start();
});
