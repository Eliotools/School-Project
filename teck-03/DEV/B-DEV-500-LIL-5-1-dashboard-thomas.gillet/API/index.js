const express = require('express')
const https = require('https');
var cors = require('cors')
var request = require('request');
var app = express()

const api_cards = "https://api.magicthegathering.io/v1/cards?types=creature&"
const api_set = "https://api.magicthegathering.io/v1/sets/"
const number = "https://numbersapi.com/"
const teck_start = "https://intra.epitech.eu/"
const teck_end = "/user/notification/message?format=json#"
const astro = "https://api.weatherapi.com/v1/astronomy.json?key=e359359a17024362ab383916212311&q="
const current = "https://api.weatherapi.com/v1/current.json?key=e359359a17024362ab383916212311&q="
const bit = "https://api.coinstats.app/public/v1/coins/"

app.use(cors())

app.get('/magic/cards/:param', (req, res) => {
    //params => [x = y] => [subtypes=gobelin]
    const params = req.params.param
    console.log(`${api_cards}${params}`)
    https.get(`${api_cards}${params}`, (resp) => {
        let data = ''
        let info = []
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            info = JSON.parse(data)
            res.status(200).json(info.cards)
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/spotify/login/:client_id&:client_secret', (req, res) => {
    // ce54a352d2be4cf59e6de5180c7a351c
    // 0b62ff184f0844a78b01507aef848653
    const client_id = req.params.client_id
    const client_secret = req.params.client_secret
    console.log(`${client_id}${client_secret}`)
    var authOptions = {
        url: 'https://accounts.spotify.com/api/token',
        headers: {
          'Authorization': 'Basic ' + Buffer.from(client_id + ':' + client_secret).toString('base64')
        },
        form: {
          grant_type: 'client_credentials'
        },
        json: true
      };
      
      request.post(authOptions, function(error, response, body) {
          if (body.error == null || body.error == undefined) {
            console.log(body)
            token = body.access_token;
            console.log(token)
            res.status(200).json("suce")
          }
        else {
            console.log("error")
        }
      })
      
/*        if (!error && response.statusCode === 200) {
      
          // use the access token to access the Spotify Web API
          console.log(response)
          var token = body.access_token;
          var options = {
            url: 'https://api.spotify.com/v1/me',
            headers: {
              'Authorization': 'Bearer ' + token
            },
            json: true
          };
          request.get(options, function(error, response, body) {
            console.log("bonjour", body, response);
          });
        }
      });*/
})

app.get('/magic/set/:param', (req, res) => {
    //params => [set] => [war]
    const params = req.params.param
    console.log(`${api_set}${params}/booster`)
    https.get(`${api_set}${params}/booster`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            info = JSON.parse(data)
            res.status(200).json(info.cards)
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

function get_user(data) {
    console.log("ici", data)
    if('error' in  data) {
        console.log('ici')
        return(["error"])
    }
    console.log('la')
    var title = []
    data.forEach(item => {
        title.push(item.user.title)
    });
    console.log(title)
    return ([...new Set(title)])
}

function get_msg(data, title) {
    console.log("data", data)
    if (data === undefined)
        return({})
    var msg = []
    console.log('data = ', data)
    console.log('title = ', title)
    data.forEach(item => {
        if (item.user.title === title) {
            console.log(typeof item.title)
            msg.push(item.title.substring(0, item.title.indexOf("href=") + 6) + "https://intra.epitech.eu" + (item.title.substring(item.title.toString().indexOf("href=") + 6)))
        }
    });
    console.log(msg)
    return ([...new Set(msg)])
}

app.get('/teck/msg/:title&:param', (req, res) => {
    //params => [Name & autologin (w\ https://intra.epitech.eu/)] => [Eliot MARTIN & auth-1748ad4c64e09a195f40986697effdaf12f31370]
    const params = req.params.param
    const title = req.params.title
    console.log(`${teck_start}${params}${teck_end}`)
    https.get(`${teck_start}${params}${teck_end}`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            console.log("laaa")
            if (title === "all")
                res.status(200).json(data)
            data = get_msg(JSON.parse(data), title)
            res.status(200).json(data)
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/teck/title/:param', (req, res) => {
    const params = req.params.param
    //params => [autologin (w\ https://intra.epitech.eu/)] => [auth-1748ad4c64e09a195f40986697effdaf12f31370]
    console.log(`${teck_start}${params}${teck_end}`)
    https.get(`${teck_start}${params}${teck_end}`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            data = get_user(JSON.parse(data))
            res.status(200).json(data)
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/cryp/:param', (req, res) => {
    const params = req.params.param
    console.log(`${bit}${params}?currency=EUR`)
    https.get(`${bit}${params}?currency=EUR`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            res.status(200).json(JSON.parse(data))
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/weather/astro/:param', (req, res) => {
    //params => [lieu] => [Lille]
    const params = req.params.param
    console.log(`${astro}${params}`)
    https.get(`${astro}${params}`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            data = JSON.parse(data)
            console.log(data)
            res.status(200).json(data)
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/weather/current/:param', (req, res) => {
    //params => [lieu] => [Lille]
    const params = req.params.param
    console.log(`${current}${params}`)
    https.get(`${current}${params}`, (resp) => {
        let data = ''
        resp.on('data', (chunk) => {
            data += chunk;
        });
        resp.on('end', () => {
            res.status(200).json(JSON.parse(data))
        });
    }).on("error", (err) => {
        console.log("Error: " + err.message);
    });
})

app.get('/about.json', (req, res) => {
    let now = new Date()  
    let secondsSinceEpoch = Math.round(now.getTime() / 1000)
    obj = {
        "client" : {
            "host" : "${req.ip}"
        },
        "server " : {
            "current_time ": "${secondsSinceEpoch}",
            "service ": [{
                "name ": "weather API",
                "widgets ": [{
                    "name ": "weather : current",
                    "description ": "Display temperature for a city",
                    "params ": [{
                        "name ": "city",
                        "type ": "string"
                    }]
                },{
                    "name ": "weather : astro",
                    "description ": "Display time of rising sun/moon for a city",
                    "params ": [{
                        "name ": "city",
                        "type ": "string"
                }]
              }]
            },{
                "name ": "magicthegathering API",
                "widgets ": [{
                    "name ": "Magic : card",
                    "description ": "Display cards by color and name",
                    "params ": [{
                        "name ": "name",
                        "type ": "string"
                    },
                    {
                        "name ": "color",
                        "type ": "string"
                    }]
                },{
                    "name ": "Magic : booster",
                    "description ": "Display booster by extentions",
                    "params ": [{
                        "name": "extention_code",
                        "type ": "string"
                }]
              }]
            },{
                "name ": "coinstats API",
                "widgets ": [{
                    "name ": "Crypto",
                    "description ": "Diplay informations about cryptomoney",
                    "params ": [{
                        "name" : "name",
                        "type ": "string",
                    }]
                }]
            },{
                "name ": "intra Epitech API",
                "widgets ": [{
                    "name ": "Epitech",
                    "description ": "Diplay message from epitech intra by name",
                    "params ": [{
                        "name" : "login",
                        "type ": "type",
                    },{
                        "name" : "name",
                        "type ": "string",
                    }]
                }]
            }] 
        }
    }
    res.status(200).json(obj)
})


app.listen(8080, () => {
    console.log("Serveur à l'écoute")
})