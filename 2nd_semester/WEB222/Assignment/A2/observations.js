/*******************************************************************************
 * Problem 00: Learning to write our tests
 ******************************************************************************/
function getResults(data) {
  return data.results;
}

/*******************************************************************************
 * Problem 01 Part 1: use a for-loop to iterate over Arrays
 ******************************************************************************/
function observationSummary(data) {
  for (let i = 0; i < data.results.length; i++) {
    console.log(
      `#${data.results[i].id} - ${data.results[i].species_guess} (${data.results[i].observed_on_details.date})`
    );
  }
}

/*******************************************************************************
 * Problem 01 Part 2: use forEach() to iterate over Arrays
 ******************************************************************************/
function observationSummary2(data) {
  data.results.forEach(function (value) {
    console.log(`#${value.id} - ${value.species_guess} (${value.observed_on_details.date})`);
  });
}

/*******************************************************************************
 * Problem 02: observationsByGeoPrivacy(data, geoPrivacy)
 ******************************************************************************/
function observationsByGeoPrivacy(data, geoPrivacy) {
  let array = [];
  if (typeof geoPrivacy === 'string' || geoPrivacy === null) {
    if (typeof geoPrivacy === 'string') {
      geoPrivacy = geoPrivacy.toLowerCase();
    }
    for (let i = 0; i < data.results.length; i++) {
      if (data.results[i].geoprivacy === geoPrivacy) {
        array.push(data.results[i]);
      }
    }
  }
  return array;
}

/*******************************************************************************
 * Problem 3 Part I: transformObservation(original) and transformObservations(cases)
 ******************************************************************************/
function transformObservation(original) {
  let Original = {
    id: original.id,
    speciesGuess: original.species_guess,
    isResearchQuality: original.quality_grade.toLowerCase() === 'research' ? true : false,
    coords: null,
    photos: null,
    user: `@${original.user.login_exact}`
  };

  let swapCood = original.location.split(',');
  let temp = Number(swapCood[0]);
  swapCood[0] = Number(swapCood[1]);
  swapCood[1] = Number(temp);
  Original.coords = swapCood;

  let photoUrl = [];
  for (let i = 0; i < original.photos.length; i++) {
    photoUrl[i] = original.photos[i].url;
  }
  Original.photos = photoUrl;
  return Original;
}

/*******************************************************************************
 * Problem 3 Part II: transformObservations(data) with iteration
 ******************************************************************************/
function transformObservations(data) {
  let arr = [];
  for (let i = 0; i < data.results.length; i++) {
    arr[i] = new Object(transformObservation(data.results[i]));
  }
  return arr;
}

/*******************************************************************************
 * Problem 3 Part III: transformObservations2(data) with .map()
 ******************************************************************************/
function transformObservations2(data) {
  let arr = [];
  arr = data.results.map(function (elements) {
    return new Object(transformObservation(elements));
  });
  return arr;
}

/*******************************************************************************
 * Problem 04: getObservationsById()
 ******************************************************************************/
function getObservationsById(data, ...ids) {
  let arr = [];
  let match = [];
  let find;

  ids.forEach(function (id) {
    find = data.results.find(function (obj) {
      return obj.id === id;
    });
    arr.push(find);
  });

  for (let i = 0; i < arr.length; i++) {
    if (arr.length === 1) {
      if (arr[i] !== undefined) {
        match = arr[i];
      } else {
        return null;
      }
    } else if (arr[i] !== undefined) {
      match.push(arr[i]);
    }
  }
  return match;
}

/*******************************************************************************
 * Problem 05: getObservationsByPositionalAccuracy()
 ******************************************************************************/
function getObservationsByPositionalAccuracy(data, options = {}) {
  let result = getResults(data);

  let match = result.filter((res) => {
    if (Object.keys(options).length === 0 || options === undefined) {
      return res;
    } else if (Object.keys(options).length === 1) {
      if (options.equal === res.positional_accuracy) {
        return res.positional_accuracy;
      } else if (options.min <= res.positional_accuracy) {
        return res.positional_accuracy;
      } else if (options.max >= res.positional_accuracy) {
        return res.positional_accuracy;
      }
    } else if (Object.keys(options).length === 2) {
      return options.max >= res.positional_accuracy && options.min <= res.positional_accuracy;
    } else if (Object.keys(options).length === 3 && options.equal === res.positional_accuracy) {
      return res.positional_accuracy;
    }
  });
  return match;
}

/*******************************************************************************
 * Problem 06: getTaxonPhotos()
 ******************************************************************************/
function getTaxonPhotos(data) {
  let result = getResults(data);
  let obj = [];

  for (let i = 0; i < result.length; i++) {
    let o;
    const taxon = result[i].taxon;
    if (!taxon) {
      return obj;
    }
    const photo = result[i].taxon.default_photo;
    if (photo !== null) {
      let picUrl = photo.url;
      let query = photo.url.substring(photo.url.indexOf('?'));
      picUrl = picUrl.split('/');
      picUrl.pop();
      picUrl = picUrl.join('/');
      o = {
        original: picUrl + '/original.jpg' + query,
        square: picUrl + '/square.jpg' + query,
        small: picUrl + '/small.jpg' + query,
        medium: picUrl + '/medium.jpg' + query,
        large: picUrl + '/large.jpg' + query
      };
      obj.push(o);
    }
  }
  return obj;
}

/*******************************************************************************
 * Problem 07: getUserStats()
 ******************************************************************************/
function getUserStats(data) {
  let result = getResults(data);
  let totals = {};
  let averages = {};
  let count = 0;
  let obsCount = 0;
  let identCount = 0;
  let speciesCount = 0;

  for (let i = 0; i < result.length; i++) {
    const user = result[i].user;
    obsCount += user.observations_count;
    identCount += user.identifications_count;
    speciesCount += user.species_count;
    count++;
  }

  totals = {
    observations: obsCount,
    identifications: identCount,
    species: speciesCount
  };

  averages = {
    observations: obsCount / count,
    identifications: identCount / count,
    species: speciesCount / count
  };

  let arr = {
    count: count,
    totals: totals,
    averages: averages
  };

  return arr;
}

// Our unit test files need to access the functions we defined
// above, so we export them here.
exports.getResults = getResults;
exports.observationSummary = observationSummary;
exports.observationSummary2 = observationSummary2;
exports.observationsByGeoPrivacy = observationsByGeoPrivacy;
exports.transformObservation = transformObservation;
exports.transformObservations = transformObservations;
exports.transformObservations2 = transformObservations2;
exports.getObservationsById = getObservationsById;
exports.getObservationsByPositionalAccuracy = getObservationsByPositionalAccuracy;
exports.getTaxonPhotos = getTaxonPhotos;
exports.getUserStats = getUserStats;
