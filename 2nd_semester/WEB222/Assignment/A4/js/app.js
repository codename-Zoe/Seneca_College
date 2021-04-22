let map;

function updateMap(observations, map) {
  // Clear the current markers on the map (if any)
  map.clear();

  // call the Simple Map's addObservation method for every one
  // of the observations in order to add markers to the map.
  observations.forEach(function (observation) {
    map.addObservation(observation);
  });
}

function updateTable(observations) {
  // Remove any current data from the table
  clearAllTableRows();

  // Populate the table with all observation data we want to show
  observations.forEach((observation) => {
    // call the buildRowForObservation function with the current observation
    // and use that to add it to the table with the addRowToTable function.
    addRowToTable(buildRowForObservation(observation));
  });
}

function showAll() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();

  // Update the map and table
  updateMap(observations, map);
  updateTable(observations);
  updateTableTitle(`All Species (${observations.length})`);
}

// Show native species on the map and table
function showOnlyNative() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();
  // Filter out any that aren't native species
  const native = filterOnlyNative(observations);

  // Update the map and table
  updateMap(native, map);
  updateTable(native);
  updateTableTitle(`Only Native Species (${native.length})`);
}

// Show introduced species on the map and table
function showOnlyIntroduced() {
  // Get all the observations from our data.js and format them so we can work with the data
  const observations = getAllObservations();
  // Filter out any that aren't introduced species
  const introduced = filterOnlyIntroduced(observations);

  // Update the map and table
  updateMap(introduced, map);
  updateTable(introduced);
  updateTableTitle(`Only Introduced Species (${introduced.length})`);
}

function start() {
  // Create our map object for Seneca's Newnham campus
  map = new SimpleMap("map-container", 43.7955, -79.3496);

  // TODO: create click handlers for all three buttons.
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
