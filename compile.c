repeat 
	task.wait()
until game:IsLoaded() and game:GetService("Players") and game:GetService("Players").LocalPlayer

if game.CoreGui:FindFirstChild('lnwza') then
	game.CoreGui:FindFirstChild('lnwza'):Destroy()
end

syn = syn or {};
local Env: SharedTable = getgenv() or getfenv()
local Configs: SharedTable = {} or { ... };
local Net: SharedTable = {} Net.__index = Net;
local Funcs: SharedTable = {} or { ... };
local META = setmetatable({}, {__index = function(_, key) return cloneref(game:GetService(key))end})
local Players, VirtualInputManager, CollectionService, ReplicatedStorage, TeleportService, RunService, VirtualUser, HttpService, TweenService, BadgeService, Chat, SoundService, Lighting, LocalizationService, PathfindingService, MarketplaceService, Stats, DataStoreService, Teams, StarterGui, StarterPack, StarterPlayer, UserInputService, GuiService, ContextActionService, ProximityPromptService, VoiceChatService = META.Players, META.VirtualInputManager, META.CollectionService, META.ReplicatedStorage, META.TeleportService, META.RunService, META.VirtualUser, META.HttpService, META.TweenService, META.BadgeService, META.Chat, META.SoundService, META.Lighting, META.LocalizationService, META.PathfindingService, META.MarketplaceService, META.Stats, META.DataStoreService, META.Teams, META.StarterGui, META.StarterPack, META.StarterPlayer, META.UserInputService, META.GuiService, META.ContextActionService, META.ProximityPromptService, META.VoiceChatService
local PlaceId, JobId, Camera, Tick, Players, RunService, LocalPlayer, Backpack, PlayerGui, PlayerScript, Name, DisplayName, PlayerId, Team, Folder, Character, HumanoidRootPart, Humanoid, RenderStepped, Heartbeat, Stepped, Executor, Blacklist_Executor = game.PlaceId, tostring(game.JobId), workspace.CurrentCamera, tick(), META.Players, META.RunService, META.Players.LocalPlayer, META.Players.LocalPlayer.Backpack, META.Players.LocalPlayer.PlayerGui, META.Players.LocalPlayer.PlayerScripts, META.Players.LocalPlayer.Name, META.Players.LocalPlayer.DisplayName, META.Players.LocalPlayer.UserId, tostring(META.Players.LocalPlayer.Team), "Fetching'Script/Config/" .. META.Players.LocalPlayer.UserId .. "/" .. game.PlaceId .. ".json", META.Players.LocalPlayer.Character or META.Players.LocalPlayer.CharacterAdded:Wait(), (META.Players.LocalPlayer.Character or META.Players.LocalPlayer.CharacterAdded:Wait()):WaitForChild("HumanoidRootPart"), (META.Players.LocalPlayer.Character or META.Players.LocalPlayer.CharacterAdded:Wait()):WaitForChild("Humanoid"), META.RunService.RenderStepped, META.RunService.Heartbeat, META.RunService.Stepped, string.upper(identifyexecutor()), table.find({"SOLARA", "XENO"}, string.upper(identifyexecutor())) if Env._ then return end Env._ = true
local GG: SharedTable = loadstring(game:HttpGet('https://github.com/java3210/dumper.gg/blob/main/library.luau?raw=true', true))()
local Window: SharedTable = GG.new(131342464463678, Enum.KeyCode.F1)
request,islclosure,getgc,hookfunction,getrenv,getgenv,identifyexecutor,setclipboard,makefolder,isfolder,writefile,isfile,readfile,delfile,sethiddenproperty,getnilinstances,cloneref,getconnections,getsenv,fireclickdetector,fireproximityprompt,firetouchinterest,getloadedmodules,getinstances,getupvalues,setupvalue,getupvalue,getconstants,getinfo,checkcaller,getcallingscript,getnamecallmethod,hookmetamethod,newcclosure,rconsoleprint,rconsolewarn,rconsoleinfo,rconsoleerr,rconsoleclear,rconsoleinput,rconsoleclose,queueonteleport,getproto,getprotos,setreadonly,isreadonly = syn.request or request, syn.islclosure or islclosure, syn.getgc or getgc, syn.hookfunction or hookfunction, syn.getrenv or getrenv, syn.getgenv or getgenv, syn.identifyexecutor or identifyexecutor, syn.setclipboard or setclipboard, syn.makefolder or makefolder, syn.isfolder or isfolder, syn.writefile or writefile, syn.isfile or isfile, syn.readfile or readfile, syn.delfile or delfile, syn.sethiddenproperty or sethiddenproperty, syn.getnilinstances or getnilinstances, syn.cloneref or cloneref, syn.getconnections or getconnections, syn.getsenv or getsenv, syn.fireclickdetector or fireclickdetector, syn.fireproximityprompt or fireproximityprompt, syn.firetouchinterest or firetouchinterest, syn.getloadedmodules or getloadedmodules, syn.getinstances or getinstances, syn.getupvalues or getupvalues, syn.setupvalue or setupvalue, syn.getupvalue or getupvalue, syn.getconstants or getconstants, syn.getinfo or getinfo, syn.checkcaller or checkcaller, syn.getcallingscript or getcallingscript, syn.getnamecallmethod or getnamecallmethod, syn.hookmetamethod or hookmetamethod, syn.newcclosure or newcclosure, syn.rconsoleprint or rconsoleprint, syn.rconsolewarn or rconsolewarn, syn.rconsoleinfo or rconsoleinfo, syn.rconsoleerr or rconsoleerr, syn.rconsoleclear or rconsoleclear, syn.rconsoleinput or rconsoleinput, syn.rconsoleclose or rconsoleclose, syn.queueonteleport or queueonteleport, syn.getproto or getproto, syn.getprotos or getprotos, syn.setreadonly or setreadonly, syn.isreadonly or isreadonly

do

	Net.loop = function(Value, interval, func, customFunc)
		while Value do local startTick = tick()
			if func then func()  end
			if customFunc and customFunc() then break end
			repeat
				RunService.Heartbeat:Wait()
			until tick() - startTick >= (interval or 0.1) 
		end
	end

	Net.again = function(f)
		task.spawn(function()
			while task.wait(0.1) do
				pcall(f)
			end
		end)
	end

	Net.save = function(key: string, value: boolean | string | number | table | any)
		if key ~= nil then Configs[key] = value;end
		if not isfolder("Fetching'Script") then makefolder("Fetching'Script");end
		writefile(Folder, HttpService:JSONEncode(Configs))
	end

	Net.default = function(v: string, a: boolean | string | number | table | any)
		if type(v) == "table" then
			for i, k in pairs(v) do
				if Configs[i] == nil then
					Configs[i] = k
				end
			end
		else
			if Configs[v] == nil then
				Configs[v] = a
			end
		end
	end

	Net.count = function(time: number, Callback: func)
		for i = 1, time do
			pcall(Callback)
		end
	end

	Net.formatnumber = function(int: number)
		return tostring(int):reverse():gsub("(%d%d%d)", "%1,"):reverse():gsub("^,", "")
	end

	Net.check = function(_table: SharedTable)
		for _,v in pairs(_table) do
			if Configs[v] == true then
				return true
			end
		end
		return false
	end

	Net.closefunc = function(a: func)
		if Blacklist_Executor then return end
		return hookfunction(a, function() return end)
	end

	Net.require = function(path: ModuleScript)
		if typeof(path) ~= 'Instance' or path.ClassName ~= 'ModuleScript' then
			error('attempt to require a ModuleScript: Is not Module Script')
		end

		if not Blacklist_Executor then return require(path) end

		local oIdentity = syn.get_thread_identity()
		syn.set_thread_identity(2)
		local g, res = pcall(require, path)
		syn.set_thread_identity(oIdentity)
		if not g then
			error(res)
		end

		return res
	end

	Net.getenv = function(v: LocalScript)
		return getsenv(v)
	end

	Net.ontrash = function(name: string)
		for _, v in pairs(getgc(true)) do
			if typeof(v) == "function" and islclosure(v) then
				if debug.getinfo(v).name == name then
					return v
				end
			end
		end
		return nil
	end

	Net.s_hop = function()
		pcall(function()
			local ListServers = function(cursor: SharedTable)
				return HttpService:JSONDecode(game:HttpGet("https://games.roblox.com/v1/games/"..PlaceId.."/servers/Public?sortOrder=Asc&limit=100" .. ((cursor and "&cursor="..cursor) or "")))
			end
			local Server, Next
			repeat
				local Servers = ListServers(Next)
				Server = Servers.data[1]
				Next = Servers.nextPageCursor
			until Server
			TeleportService:TeleportToPlaceInstance(PlaceId,Server.id,LocalPlayer)
		end)
	end

	Net.rejoin = function()
		if #Players:GetPlayers() <= 1 then
			LocalPlayer:Kick("\nRejoining...")
			wait()
			TeleportService:Teleport(PlaceId, LocalPlayer)
		else
			TeleportService:TeleportToPlaceInstance(PlaceId, JobId, LocalPlayer)
		end
	end

	Net.distance = function(v: any)
		if HumanoidRootPart then
			if typeof(v) == "Instance" and v:IsA("Model") then
				return (v:GetPivot().Position - HumanoidRootPart.Position).Magnitude
			elseif typeof(v) == "Instance" and v:IsA("BasePart") then
				return (v.Position - HumanoidRootPart.Position).Magnitude
			elseif typeof(v) == "CFrame" then
				return (v.Position - HumanoidRootPart.Position).Magnitude
			elseif typeof(v) == "Vector3" then
				return (v - HumanoidRootPart.Position).Magnitude
			elseif typeof(v) == 'table' then
				return (Vector3.new(v[1], v[2], v[3]) - HumanoidRootPart.Position).Magnitude
			end
		end
		return nil
	end

	Net.alive = function(v: Model | Instance | any)
		return typeof(v) == "Instance"and v:IsA("Model")and v:FindFirstChild("Humanoid") and v:FindFirstChild("Humanoid").Health > 0;
	end

	Net.touchconnect = function(v: BasePart)
		if not v:IsA("BasePart") then return end
		firetouchinterest(HumanoidRootPart, v, 1)
		firetouchinterest(HumanoidRootPart, v, 0)
	end

	Net.prompt = function(v: ProximityPrompt)
		if not v:IsA("ProximityPrompt") then return end
		fireproximityprompt(v)
	end

	Net.clickdector = function(v: ClickDetector)
		if not v:IsA("ClickDetector") then return end
		fireclickdetector(v)
	end

	Net.render = function()
		return Heartbeat:Wait()
	end

	Net.html = function(text: string, color: Color3)
		if type(text) == "string" and typeof(color) == "Color3" then
			local r, g, b = math.floor(color.R * 255), math.floor(color.G * 255), math.floor(color.B * 255)
			return string.format('<font color="rgb(%d, %d, %d)">%s</font>', r, g, b, text)
		end
		return text
	end

	Net.lock = function(value: boolean)
		if not HumanoidRootPart then return end
		if value then
			if not HumanoidRootPart:FindFirstChild("Lock") then
				local BodyVelocity = Instance.new("BodyVelocity")
				BodyVelocity.Name = "Lock"
				BodyVelocity.Parent = HumanoidRootPart
				BodyVelocity.MaxForce = Vector3.new(0, math.huge, 0)
				BodyVelocity.Velocity = Vector3.new(0, 0, 0)
			end
		else
			if HumanoidRootPart:FindFirstChild("Lock") then
				HumanoidRootPart:FindFirstChild("Lock"):Destroy()
			end
		end
	end

	Net.tween = function(target: CFrame)
		if not Character then return end
		for _, v in pairs(Character:GetDescendants()) do
			if v:IsA("BasePart") then v.CanCollide = false end
		end
		if not HumanoidRootPart:FindFirstChild("BodyVelocity222") then
			local BodyVelocity = Instance.new("BodyVelocity")
			BodyVelocity.Name = "BodyVelocity222"
			BodyVelocity.Parent = HumanoidRootPart
			BodyVelocity.MaxForce = Vector3.new(0, math.huge, 0)
			BodyVelocity.Velocity = Vector3.new(0, 0, 0)
		end
		local Distance = (target.Position - HumanoidRootPart.Position).Magnitude
		if Distance > 0 and Distance < 300 then
			return TweenService:Create(HumanoidRootPart,TweenInfo.new(0.08, Enum.EasingStyle.Linear),{CFrame = target}):Play()
		else
			local tw = TweenService:Create(HumanoidRootPart,TweenInfo.new(Distance / 300, Enum.EasingStyle.Linear),{CFrame = target})
			function S()
				if tw then
					tw:Cancel()
				end
				if HumanoidRootPart:FindFirstChild("BodyVelocity222") then
					HumanoidRootPart:FindFirstChild("BodyVelocity222"):Destroy()
				end 
			end
			return tw:Play()
		end
	end

	Net.stoptw = function(v)
		if not v then pcall(S) end
	end

	Net.tp = function(pos: any, v: boolean)
		if not HumanoidRootPart then return end
		if typeof(pos) == "CFrame" then
			HumanoidRootPart.CFrame = v and (pos * CFrame.Angles(math.rad(-90), 0, 0)) or pos
		elseif typeof(pos) == "Vector3" then
			HumanoidRootPart.CFrame = v and (CFrame.new(pos) * CFrame.Angles(math.rad(-90), 0, 0)) or CFrame.new(pos)
		elseif typeof(pos) == "Instance" and pos:IsA("Model") then
			HumanoidRootPart.CFrame = v and (pos:GetPivot() * CFrame.Angles(math.rad(-90), 0, 0)) or pos:GetPivot()
		elseif typeof(pos) == "Instance" and pos:IsA("BasePart") then
			HumanoidRootPart.CFrame = v and (pos.CFrame * CFrame.Angles(math.rad(-90), 0, 0)) or pos.CFrame
		elseif typeof(pos) == 'table' then
			HumanoidRootPart.CFrame = v and (pos.CFrame * CFrame.Angles(math.rad(-90), 0, 0)) or CFrame.new(pos[1], pos[2], pos[3])
		end
	end

	Net.spin = function(v: Vector3)
		if not HumanoidRootPart then return end
		HumanoidRootPart.Rotation = v;
	end

	Net.closet_mobs = function(v: Folder | any?)
		local closest, dist, hp = nil, math.huge, math.huge
		for _, mob in ipairs(v:GetChildren()) do
			if mob:IsA("Model") and Net.alive(mob) then
				local d = Net.distance(mob)
				local h = mob:FindFirstChild("Humanoid").Health
				if d < dist or (d == dist and h < hp) then
					dist, hp, closest = d, h, mob
				end
			end
		end
		return closest
	end

	Net.closet_players = function()
		local closest, dist, hp = nil, math.huge, math.huge
		for _, player in ipairs(Players:GetPlayers()) do
			if player ~= LocalPlayer and player.Character and Net.alive(player.Character) then
				local d = Net.distance(player.Character)
				local h = player.Character:FindFirstChild("Humanoid").Health
				if d < dist or (d == dist and h < hp) then
					dist, hp, closest = d, h, player
				end
			end
		end
		return closest;
	end

	Net.equip = function(Tool: Tool | string)
		if not Character then return end
		return Humanoid:EquipTool(Tool)
	end

	Net.have = function(v)
		return Character:FindFirstChild(v) or Backpack:FindFirstChild(v)
	end

	Net.request = function(url, meta)
		local msg = {
			username = meta.username,
			embeds = {{
				title = meta.title,
				color = 65280,
				fields = meta.fields,
				image = {
					url = meta.image
				}
			}}
		}

		request({
			Url = url,
			Method = "POST",
			Headers = {
				["Content-Type"] = "application/json"
			},
			Body = HttpService:JSONEncode(msg)
		})

		--[[
		
		Net.request("https://discord.com/api/webhooks/xxxxxxxxx", {
		username = "ระบบแจ้งเตือน",
		title = "มีผู้เล่นเข้าสู่ระบบ",
		fields = {
			{ name = "ชื่อผู้เล่น", value = "Player123", inline = true },
			{ name = "เวลา", value = "12:00", inline = true }
		},
			image = "https://example.com/image.png"
		})
		
		]]
	end

	Net.load = function()
		local base = "Fetching'Script/Config/" .. PlayerId
		local path = base .. "/" .. PlaceId .. ".json"
		if not isfolder("Fetching'Script") then makefolder("Fetching'Script") end
		if not isfolder("Fetching'Script/Config") then makefolder("Fetching'Script/Config") end
		if not isfolder(base) then makefolder(base) end
		if not isfile(path) then Net:save() end
		return HttpService:JSONDecode(readfile(path))
	end

	Env.include = function(studio: syn)
		if type(studio) == 'string' then
			LocalPlayer.CharacterAdded:Connect(function(newCharacter: Instance)
				Character = newCharacter;
				Humanoid = Character:WaitForChild('Humanoid');
				HumanoidRootPart = Character:WaitForChild('HumanoidRootPart');
				Backpack = LocalPlayer:WaitForChild("Backpack");
			end)
			LocalPlayer.Idled:Connect(function()
				VirtualUser:CaptureController();
				VirtualUser:ClickButton2(Vector2.new());
			end)
			print("Start: " .. studio)
		else
			while true do end
		end
	end

	Env.c = function(f: Folder)
		if not f then return end
		for _, v in pairs(f:GetChildren()) do
			return v
		end
	end

	Env.d = function(f: Folder)
		if not f then return end
		for _, v in ipairs(f:GetDescendants()) do
			return v
		end
	end

	Env.t = function(f: Folder)
		if not f or type(f) ~= 'table' then return end
		for _, v in pairs(f) do
			return v
		end
	end

	Env.f = function(n: Instance ,i: string, d: boolean)
		return (d and d ~= nil and n:FindFirstChild((i and tostring(i)), true)) or n:FindFirstChild(i and tostring(i))
	end

	Env.fc = function(n: Instance ,i: string, d: boolean)
		return (d and d ~= nil and n:FindFirstChildOfClass((i and tostring(i)), true)) or n:FindFirstChildOfClass(i and tostring(i))
	end

	Net.round = function(n: number)
		return math.floor(tonumber(n) + 1)
	end

	Net.esp = function(meta: table)
		local v = meta.Instance
		local title = meta.Name or v.Name
		local MainColor = meta.Color or Color3.fromRGB(255, 255, 255)
		local DropColor = meta.Drop or Color3.fromRGB(127, 127, 127)
		if not v:FindFirstChild('Constant') then
			local bill = Instance.new('BillboardGui',v)
			bill.Name = 'Constant'
			bill.Size = UDim2.fromOffset(100, 100)
			bill.MaxDistance = math.huge
			bill.Adornee = v
			bill.AlwaysOnTop = true

			local circle = Instance.new("Frame", bill)
			circle.Position = UDim2.fromScale(0.5, 0.5)
			circle.AnchorPoint = Vector2.new(0.5, 0.5)
			circle.Size = UDim2.fromOffset(6, 6)
			circle.BackgroundColor3 = Color3.fromRGB(255,255,255)

			local gradient = Instance.new("UIGradient", circle)
			gradient.Rotation = 90
			gradient.Color = ColorSequence.new({ColorSequenceKeypoint.new(0, MainColor), ColorSequenceKeypoint.new(1, DropColor)})

			local stroke = Instance.new("UIStroke", circle)
			stroke.Thickness = 0.5

			local name = Instance.new('TextLabel',bill)
			name.Font = Enum.Font.GothamBold
			name.AnchorPoint = Vector2.new(0, 0.5)
			name.Size = UDim2.fromScale(1, 0.3)
			name.TextScaled = true
			name.BackgroundTransparency = 1
			name.TextStrokeTransparency = 0
			name.TextStrokeColor3 = Color3.fromRGB(0, 0, 0)
			name.Position = UDim2.new(0, 0, 0.5, 24)
			name.TextColor3 = Color3.fromRGB(255, 255, 255)
			name.Text = "nil"

			local gradient = Instance.new("UIGradient", name)
			gradient.Rotation = 0
			gradient.Color = ColorSequence.new({ColorSequenceKeypoint.new(0, MainColor), ColorSequenceKeypoint.new(1, DropColor)})
		else
			if v:IsA("Model") then
				v:FindFirstChild('Constant'):FindFirstChild("TextLabel").Text = title .. '\n[ ' .. Net.round((HumanoidRootPart.Position - v:GetPivot().Position).Magnitude / 3) .. ' ]'
			elseif v:IsA("BasePart") then
				v:FindFirstChild('Constant'):FindFirstChild("TextLabel").Text = title .. '\n[ ' .. Net.round((HumanoidRootPart.Position - v.Position).Magnitude / 3) .. ' ]'
			end
		end
	end

	Net.unesp = function(v: Instance)
		if v:FindFirstChild('Constant') then
			v:FindFirstChild('Constant'):Destroy()
		end
	end

	Configs = Net.load()

	Net.Toggle = function(Tab, Title, SettingName, CallBack)
		local tasks;
		return Tab:Toggle(Title, Configs[SettingName], function(val)
			Configs[SettingName] = val
			Net.save(SettingName, Configs[SettingName] or val)
			if val then
				tasks = task.spawn(function()
					if Funcs[SettingName] then
						Funcs[SettingName](Configs[SettingName])
					end
				end)
			else
				Net.stoptw(val)
				if tasks ~= nil then
					task.cancel(tasks)
				end
			end
			if CallBack ~= nil then
				CallBack(val)
			end
		end)
	end

	Net.Text = function(tab: SharedTable, v: string, callback: func)
		local Paragarp = tab:Label(v)
		if callback ~= nil then
			Net.again(function()
				callback(Paragarp)
			end)
		end
		return Paragarp
	end
end


task.spawn(function()
	local Home = Window:Tab("Home")
	local Ds = Home:Section("Discord", "l") do
		Net.Text(Ds, "Join Discord")
		Ds:Button("Discord", function()
			setclipboard('https://discord.gg/9ymQNuDbHs')
		end)
	end
	local Performance = Home:Section("Performance", "r") do
		Net.Toggle(Performance, "White Screen", function(v)
			if v then
				RunService:Set3dRenderingEnabled(false)
			else
				RunService:Set3dRenderingEnabled(true)
			end
		end)
		Net.Toggle(Performance, "Fullbright", 'Fullbright')
		Performance:Button("Boost CPU", function()
			pcall(function()
				local Terrain = workspace:FindFirstChildOfClass('Terrain')
				Terrain.WaterWaveSize = 0
				Terrain.WaterWaveSpeed = 0
				Terrain.WaterReflectance = 0
				Terrain.WaterTransparency = 0
				game.Lighting.GlobalShadows = false
				game.Lighting.FogEnd = 9e9
				settings().Rendering.QualityLevel = 1
				for i,v in pairs(game:GetDescendants()) do
					if v:IsA("Part") or v:IsA("UnionOperation") or v:IsA("MeshPart") or v:IsA("CornerWedgePart") or v:IsA("TrussPart") then
						v.Material = "Plastic"
						v.Reflectance = 0
					elseif v:IsA("Decal") then
						v.Transparency = 1
					elseif v:IsA("ParticleEmitter") or v:IsA("Trail") then
						v.Lifetime = NumberRange.new(0)
					elseif v:IsA("Explosion") then
						v.BlastPressure = 1
						v.BlastRadius = 1
					end
				end
				for i,v in pairs(Lighting:GetDescendants()) do
					if v:IsA("BlurEffect") or v:IsA("SunRaysEffect") or v:IsA("ColorCorrectionEffect") or v:IsA("BloomEffect") or v:IsA("DepthOfFieldEffect") then
						v.Enabled = false
					end
				end
			end)
		end)
	end

	local Server = Home:Section("Server", 'l') do
		Net.default('Input JobID', JobId)
		Server:Textbox({Value = "Input JobID", function(v)
			Configs["Input JobID"] = v
			Net.save("Input JobID", v)
		end})
		Server:Button("Join", function()
			TeleportService:TeleportToPlaceInstance(PlaceId, Configs['Input JobID'], LocalPlayer)
		end)
		Server:Button("Clipboard", function()
			setclipboard(JobId)
		end)
		Server:Button("Rejoin", function()
			Net.rejoin()
		end)
		Server:Button("Change Server", function()
			Net.s_hop()
		end)
	end

	local PlayersSS = Home:Section("Players", 'l') do
		Net.Text(PlayersSS, "All Players : N/A", function(v)
			v:Title("All Players : " .. Net.html(tostring(#Players:GetPlayers() .. " / " .. Players.MaxPlayers), Color3.fromRGB(255, 0, 127)))
		end)

		local AllPlayer = {}

		for _, v in pairs(Players:GetPlayers()) do
			if v ~= LocalPlayer and v.Character then
				table.insert(AllPlayer, v.Name)
			end
		end

		Net.default('Select Player', AllPlayer[1])
		local PlayerDropdown = PlayersSS:Dropdown({Title = "Select Players",Multi = false,List = AllPlayer,Value = Configs['Select Player'],Callback = function(v)
			Configs['Select Player'] = v
			Net.save('Select Player', v)
		end})
		
		PlayersSS:Button("Refresh", function()
			PlayerDropdown:Clear()
			for _, v in pairs(Players:GetPlayers()) do
				if v ~= LocalPlayer and v.Character then
					PlayerDropdown:AddList(v.Name)
				end
			end
		end)
		
		PlayersSS:Button("Teleport to Player", function()
			pcall(Net.tp, Players:FindFirstChild(Configs["Select Player"]) and Players[Configs["Select Player"]].Character)
		end)

		Funcs['Tween Player'] = function(Value)
			Net.loop(Value, 0.1, function()
				pcall(Net.tween, Players:FindFirstChild(Configs["Select Player"]) and Players[Configs["Select Player"]].Character:GetPivot() + Vector3.new(0, 40, 0))
			end, function()
				return not Value
			end)
		end

		Net.Toggle(PlayersSS, "Tween to Player", 'Tween Player')
		Net.Toggle(PlayersSS, "View Players", 'View Player', function(v)
			if v then
				Camera.CameraSubject = Players:FindFirstChild(Configs["Select Player"]) and Players[Configs["Select Player"]].Character
			else
				Camera.CameraSubject = Humanoid
			end
		end)
	end

	local Power = Home:Section("Powers", 'r') do
		local OldSpeed = Humanoid.WalkSpeed
		Net.default('Walkspeed', Humanoid.WalkSpeed)

		local CFloop
		Power:Toggle("CFLY", false, function(v)
			if v then
				Humanoid.PlatformStand = true
				local Head = Character:WaitForChild("Head")
				Head.Anchored = true
				if CFloop then CFloop:Disconnect() end
				CFloop = RunService.Heartbeat:Connect(function(deltaTime)
					local moveDirection = Character:FindFirstChildOfClass('Humanoid').MoveDirection * (100 * deltaTime)
					local headCFrame = Head.CFrame
					local cameraCFrame = workspace.CurrentCamera.CFrame
					local cameraOffset = headCFrame:ToObjectSpace(cameraCFrame).Position
					cameraCFrame = cameraCFrame * CFrame.new(-cameraOffset.X, -cameraOffset.Y, -cameraOffset.Z + 1)
					local cameraPosition = cameraCFrame.Position
					local headPosition = headCFrame.Position

					local objectSpaceVelocity = CFrame.new(cameraPosition, Vector3.new(headPosition.X, cameraPosition.Y, headPosition.Z)):VectorToObjectSpace(moveDirection)
					Head.CFrame = CFrame.new(headPosition) * (cameraCFrame - cameraPosition) * CFrame.new(objectSpaceVelocity)
				end)
			else
				if CFloop then
					CFloop:Disconnect()
					Humanoid.PlatformStand = false
					local Head = Character:WaitForChild("Head")
					Head.Anchored = false
				end
			end
		end)

		Power:Slider({Title = "Speed",Min = 16,Max = 150,Value = Configs['Walkspeed'], CallBack = function(v)
			Configs['Walkspeed'] = v
			Net.save('Walkspeed', v)
			Humanoid.WalkSpeed = v
		end})

		Power:Button("Change to Old Walkspeed", function()
			Humanoid.WalkSpeed = OldSpeed
		end)

		LocalPlayer.CharacterAdded:Connect(function(char)
			char:WaitForChild("Humanoid").WalkSpeed = Configs['Walkspeed']
		end)
	end

	local Config = Home:Section("Configs", 'r') do
		Net.Toggle(Config, "Keep Script", 'Keep Script')
		Config:Button("Reset Configs", function()
			delfile(Folder)
		end)
	end
end)

do

	_G.NormalLightingSettings = {
		Brightness = Lighting.Brightness,
		ClockTime = Lighting.ClockTime,
		FogEnd = Lighting.FogEnd,
		GlobalShadows = Lighting.GlobalShadows,
		Ambient = Lighting.Ambient
	}

	Lighting:GetPropertyChangedSignal("Brightness"):Connect(function()
		if Lighting.Brightness ~= 1 and Lighting.Brightness ~= _G.NormalLightingSettings.Brightness then
			_G.NormalLightingSettings.Brightness = Lighting.Brightness
			if not Configs['Fullbright'] then
				repeat
					wait()
				until Configs['Fullbright']
			end
			Lighting.Brightness = 1
		end
	end)

	Lighting:GetPropertyChangedSignal("ClockTime"):Connect(function()
		if Lighting.ClockTime ~= 12 and Lighting.ClockTime ~= _G.NormalLightingSettings.ClockTime then
			_G.NormalLightingSettings.ClockTime = Lighting.ClockTime
			if not Configs['Fullbright'] then
				repeat
					wait()
				until Configs['Fullbright']
			end
			Lighting.ClockTime = 12
		end
	end)

	Lighting:GetPropertyChangedSignal("FogEnd"):Connect(function()
		if Lighting.FogEnd ~= 786543 and Lighting.FogEnd ~= _G.NormalLightingSettings.FogEnd then
			_G.NormalLightingSettings.FogEnd = Lighting.FogEnd
			if not Configs['Fullbright'] then
				repeat
					wait()
				until Configs['Fullbright']
			end
			Lighting.FogEnd = 786543
		end
	end)

	Lighting:GetPropertyChangedSignal("GlobalShadows"):Connect(function()
		if Lighting.GlobalShadows ~= false and Lighting.GlobalShadows ~= _G.NormalLightingSettings.GlobalShadows then
			_G.NormalLightingSettings.GlobalShadows = Lighting.GlobalShadows
			if not Configs['Fullbright'] then
				repeat
					wait()
				until Configs['Fullbright']
			end
			Lighting.GlobalShadows = false
		end
	end)

	Lighting:GetPropertyChangedSignal("Ambient"):Connect(function()
		if Lighting.Ambient ~= Color3.fromRGB(178, 178, 178) and Lighting.Ambient ~= _G.NormalLightingSettings.Ambient then
			_G.NormalLightingSettings.Ambient = Lighting.Ambient
			if not Configs['Fullbright'] then
				repeat
					wait()
				until Configs['Fullbright']
			end
			Lighting.Ambient = Color3.fromRGB(178, 178, 178)
		end
	end)

	Lighting.Brightness = 1
	Lighting.ClockTime = 12
	Lighting.FogEnd = 786543
	Lighting.GlobalShadows = false
	Lighting.Ambient = Color3.fromRGB(178, 178, 178)

	local LatestValue = true
	Net.again(function()
		if Configs['Fullbright'] ~= LatestValue then
			if not Configs['Fullbright'] then
				Lighting.Brightness = _G.NormalLightingSettings.Brightness
				Lighting.ClockTime = _G.NormalLightingSettings.ClockTime
				Lighting.FogEnd = _G.NormalLightingSettings.FogEnd
				Lighting.GlobalShadows = _G.NormalLightingSettings.GlobalShadows
				Lighting.Ambient = _G.NormalLightingSettings.Ambient
			else
				Lighting.Brightness = 1
				Lighting.ClockTime = 12
				Lighting.FogEnd = 786543
				Lighting.GlobalShadows = false
				Lighting.Ambient = Color3.fromRGB(178, 178, 178)
			end
			LatestValue = not LatestValue
		end
	end)
	local TeleportCheck = false
	LocalPlayer.OnTeleport:Connect(function(State)
		if Configs['Keep Script'] and (not TeleportCheck) and queueonteleport then
			TeleportCheck = true
			print('Success')
			queueonteleport(Configs['buffer'])
		end
	end)
end

return {Net;Funcs;Env;Configs;Window;Players;LocalPlayer;ReplicatedStorage}
