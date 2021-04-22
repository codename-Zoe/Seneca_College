// Add the text to the <span>...<span> element in the element with id=table-title
function updateCardTitle(title) {
  newTitle = document.querySelector("#card-title span");
  newTitle.innerText = title;
}

//Remove all content from the table body element with id=rows
function clearAllCards() {
  let cards = document.querySelector("#observation-cards");
  while (cards.lastElementChild) {
    cards.removeChild(cards.lastElementChild);
  }
}

// Given a string of text, create and return a TextNode
function createText(text) {
  return document.createTextNode(text);
}

// create and return an anchor element.
function createAnchor(href, innerContent) {
  let anchor = document.createElement("a");
  anchor.href = href;
  anchor.appendChild(createText(innerContent));
  return anchor;
}

//It accepts an observation’s photo URL
function cardImg(url) {
  let newDiv = document.createElement("div");
  newDiv.setAttribute("class", "card-img");
  url = url.replace("square", "medium");
  newDiv.style.backgroundImage = `url(${url})`;
  return newDiv;
}

//It accepts observation properties and use them to create the card’s body (a <div>).
function cardBody(name, date, uri, wikipediaUrl) {
  let newDiv = document.createElement("div");
  let h4 = document.createElement("h4");
  let h3 = document.createElement("h3");
  date = date.toISOString().split("T")[0];
  newDiv.setAttribute("class", "card-body");
  h3.appendChild(createAnchor(wikipediaUrl, name));
  h4.appendChild(createAnchor(uri, date));
  newDiv.appendChild(h3);
  newDiv.appendChild(h4);
  return newDiv;
}

//It accepts observation properties and use them to create the icons
function cardIcons(isNative, isIntroduced, isThreatened, isEndangered) {
  let newDiv = document.createElement("div");
  newDiv.setAttribute("class", "card-icons");
  if (isNative) {
    let element = document.createElement("i");
    element.setAttribute("class", "fas fa-leaf");
    element.title = "Native";
    newDiv.appendChild(element);
  }
  if (isIntroduced) {
    let element = document.createElement("i");
    element.setAttribute("class", "fas fa-frog");
    element.title = "Introduced";
    newDiv.appendChild(element);
  }
  if (isThreatened) {
    let element = document.createElement("i");
    element.setAttribute("class", "fas fa-radiation-alt");
    element.title = "Threatened";
    newDiv.appendChild(element);
  }
  if (isEndangered) {
    let element = document.createElement("i");
    element.setAttribute("class", "fas fa-skull-crossbones");
    element.title = "Endangered";
    newDiv.appendChild(element);
  }
  return newDiv;
}

//It creates cards for each observation, and add them to your observation-cards div
function buildCardForObservation(observation) {
  let div = document.createElement("div");
  div.setAttribute("class", "card");
  div.id = observation.id;
  div.appendChild(cardImg(observation.photoUrl));
  div.appendChild(
    cardBody(
      observation.name,
      observation.date,
      observation.uri,
      observation.wikipediaUrl
    )
  );
  div.appendChild(
    cardIcons(
      observation.isNative,
      observation.isIntroduced,
      observation.isThreatened,
      observation.isEndangered
    )
  );
  document.querySelector("#observation-cards").appendChild(div);
  return div;
}
