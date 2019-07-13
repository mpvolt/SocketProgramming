 require 'watir'
  
  dayCounter = 0
  hourCounter = 0
  followCount = 0

  username = ARGV[0]
  password = "Your password"
  
  user = "jayalvarrez"
  
  #open browser, navigate to login page
  browser = Watir::Browser.new :chrome, switches: ['--incognito']
  browser.goto "https://www.instagram.com/accounts/login/"
  
  #log into instagram
  puts "Logging in.."
  browser.text_field(:name => "username").set "#{username}"
  browser.text_field(:name => "password").set "#{password}"
  
  #Click login button
  browser.button(:class => '_0mzm- sqdOP  L3NKy       ').click
  sleep(2)
  
  
  browser.goto "instagram.com/#{user}/"
  sleep(3)
  browser.a(:'href' => "/#{user}/followers/").click
  sleep(2)

while true 
while dayCounter < 200
  while hourCounter < 20
	if browser.button(:class => "_0mzm- sqdOP  L3NKy       ").exists?
		browser.button(:class => "_0mzm- sqdOP  L3NKy       ").click
	        hourCounter+=1
	        sleep(3)
        end
  end

  hourCounter = 0 	#Reset Hourly Counter
  dayCounter += 20 	#Followers per day counter +20
  #browser.driver.execute_script("window.scrollBy(0, document.body.scrollHeight)")
  sleep(3600)  		#Sleep for an hour
end
dayCounter = 0
hourCounter = 0
end
#  if browser.button(:class => '_0mzm- sqdOP  L3NKy       ').exists?
#	browser.button(:class => '_0mzm- sqdOP  L3NKy       ').click
  
#  while true
#  	if browser.button(:class => '_0mzm- sqdOP  L3NKy       ').exists?
#  	 ap "Following #{val}"
#  	 browser.button(:class => '_0mzm- sqdOP  L3NKy       ').click
#  	 sleep(5)
#  	else
#  	 browser.driver.execute_script("window.scrollBy(0, document.body.scrollHeight)")

puts "-------------- #{Time.now} ----------------"
	
	sleep(30)
  
  
	
 # pry.start(binding)


# users = ['instagram', 'selenagomez', 'arianagrande', 'taylorswift', 'beyonce', 'kimkardashian', 'cristiano', 'kyliejenner', 'justinbieber', 'kendalljenner', 'nickiminaj', 'natgeo', 'neymarjr', 'nike', 'leomessi','khloekardashian', 'mileycyrus', 'katyperry', 'jlo', 'ddlovato', 'kourtneykardash', 'victoriasecret', 'badgalriri', 'fcbarcelona', 'realmadrid', 'theellenshow', 'justintimberlake', 'zendaya' 'caradelevingne', '9gag', 'chrisbrownofficial', 'vindiesel', 'champagnepapi', 'davidbeckham', 'shakira', 'gigihadid', 'emmawatson', 'jamesrodiguez10', 'kingjames', 'garethbale11', 'nikefootball', 'adele', 'zacefron', 'vanessahudgens', 'ladygaga', 'maluma', 'nba', 'nasa', 'rondaldinho', 'luissuarez9', 'zayn', 'shawnmendes', 'adidasfootball', 'brumarquezine', 'hm', 'harrystyles','chanelofficial', 'ayutingting92', 'letthelordbewithyou', 'niallhoran', 'anitta', 'hudabeauty', 'camerondallas', 'adidasoriginals', 'marinaruybarbosa', 'lucyhale', 'karimbenzema', 'princessyahrini', 'zara', 'nickyjampr', 'onedirection', 'andresiniesta8', 'raffinagita1717', 'krisjenner', 'manchesterunited', 'natgeotravel', 'marcelottwelve', 'deepikapadukone', 'snoopdogg', 'davidluiz_4', 'kalbiminrozeti', 'priyankachopra', 'ashleybenson', 'shaym', 'lelepons', 'prillylatuconsina96','louisvuitton','britneyspears', 'sr4official', 'jbalvin', 'laudyacynthiabella', 'ciara', 'stephencurry30', 'instagrambrasil']
