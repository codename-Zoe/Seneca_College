// Add the text to the <span>...<span> element in the element with id=observation-title
function updateTitle(text) {
  const title = document.querySelector("#observation-title > span");
  title.innerText = text;
}

// Remove all content from the cards div
function clearAllCards() {
  const cards = document.querySelector("#observation-cards");
  cards.innerHTML = "";
}

function addCard(card) {
  const cards = document.querySelector("#observation-cards");
  cards.appendChild(card);
}

function createAnchor(href, innerContent) {
  const a = document.createElement("a");
  a.href = href;
  a.innerText = innerContent;
  return a;
}

function cardImg(url) {
  url = url.replace("square", "medium");
  const div = document.createElement("div");
  div.className = "card-img";
  div.style = `background-image: url(${url})`;

  return div;
}

function cardBody(name, date, uri, wikipediaUrl) {
  const body = document.createElement("div");
  body.className = "card-body";

  const nameAnchor = createAnchor(wikipediaUrl, name);
  const h3 = document.createElement("h3");
  h3.appendChild(nameAnchor);
  body.appendChild(h3);

  const dateAnchor = createAnchor(uri, date.toLocaleDateString());
  const h4 = document.createElement("h4");
  h4.appendChild(dateAnchor);
  body.appendChild(h4);

  return body;
}

function cardIcons(isNative, isIntroduced, isThreatened, isEndangered) {
  const icons = document.createElement("div");
  icons.className = "card-icons";

  function cardIcon(classes, title) {
    const icon = document.createElement("i");
    icon.className = classes;
    icon.title = title;
    return icon;
  }

  if (isNative) {
    // <i class="fas fa-leaf" title="Native"></i>
    icons.appendChild(cardIcon("fas fa-leaf", "Native"));
  }

  if (isIntroduced) {
    // <i class="fas fa-frog" title="Introduced"></i>
    icons.appendChild(cardIcon("fas fa-frog", "Introduced"));
  }

  if (isThreatened) {
    // <i class="fas fa-radiation-alt" title="Threatened"></i>
    icons.appendChild(cardIcon("fas fa-radiation-alt", "Threatened"));
  }

  if (isEndangered) {
    // <i class="fas fa-skull-crossbones" title="Endangered">
    icons.appendChild(cardIcon("fas fa-skull-crossbones", "Endangered"));
  }

  return icons;
}

function buildCardForObservation(observation) {
  const {
    id,
    name,
    photoUrl,
    date,
    uri,
    wikipediaUrl,
    isNative,
    isEndangered,
    isIntroduced,
    isThreatened,
  } = observation;

  const card = document.createElement("div");
  card.className = "card";
  card.id = id;

  card.appendChild(cardImg(photoUrl));
  card.appendChild(cardBody(name, date, uri, wikipediaUrl));
  card.appendChild(
    cardIcons(isNative, isIntroduced, isThreatened, isEndangered)
  );

  return card;
}

function toggleLoading(isLoading) {
  // Toggle the state of the Search button. When we click 'Search' we need to
  // indicate to the user that we're doing something (i.e., that we're Loading...).
  if (isLoading) {
    let button = document.querySelector("button");
    let icon = document.createElement("i");
    icon.setAttribute("class", "fas fa-hourglass-half");
    button.innerText = "Loading…";
    button.prepend(icon);
    button.disabled = true;
  } else {
    let button = document.querySelector("button");
    let icon = document.createElement("i");
    icon.setAttribute("class", "fas fa-search");
    button.innerText = "Search";
    button.prepend(icon);
    button.disabled = false;
  }
  console.log("TODO - toggle the state of the Search button to/from Loading");
}
