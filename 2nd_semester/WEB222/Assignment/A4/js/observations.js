// Given a string, convert the first letter of each word in the
// string to a capital letter. 
function titleCase(s) {
  let str = s.split(" ");
  for (let i = 0; i < str.length; i++) {
    str[i] = str[i].charAt(0).toUpperCase() + str[i].slice(1);
  }
  return str.join(" ");
}

// Given an Array of iNaturalist observation objects, transform the objects into
// our desired format, and return the new Array. 
function transformObservations(observations) {
  return observations.map(function (observation) {
    let object = {};
    object.id = observation.id;
    object.uri = observation.uri;
    object.coords = observation.geojson.coordinates;
    object.date = new Date(observation.created_at);
    if (observation.taxon.preferred_common_name) {
      object.name = titleCase(observation.taxon.preferred_common_name);
    } else {
      object.name = titleCase(observation.taxon.name);
    }
    object.photoUrl = observation.taxon.default_photo.square_url;
    object.wikipediaUrl = observation.taxon.wikipedia_url;
    object.isNative = Boolean(observation.taxon.native);
    object.isIntroduced = Boolean(observation.taxon.introduced);
    object.isEndangered = Boolean(observation.taxon.endangered);
    object.isThreatened = Boolean(observation.taxon.threatened);
    return object;
  });
}

// Take the array of observations and filter out any observations that haven't
// been identified yet (i.e., are missing the `taxon` property) and/or don't have
// a photo (i.e., are missing the `taxon.default_photo` property).
function filterObservations(observations) {
  return observations.filter(function (observation) {
    if (observation.taxon) {
      if (observation.taxon.default_photo) {
        return observation;
      }
    }
  });
}

// Process all observation data in the window.data.results array (see data.js)
// to a simpler format we can work with, and filter the observations to get
// rid of any that are missing data that we need.
function getAllObservations() {
  const filtered = filterObservations(data.results);
  const transformed = transformObservations(filtered);
  return transformed;
}

// Given an array of observations, filter out any that aren't native species
// and return the filtered array.
function filterOnlyNative(observations) {
  return observations.filter(function (observation) {
    if (observation.isNative) {
      return observation;
    }
  });
}

// Given an array of observations, filter out any that aren't introduced species
// and return the filtered array.
function filterOnlyIntroduced(observations) {
  return observations.filter(function (observation) {
    if (observation.isIntroduced) {
      return observation;
    }
  });
}
