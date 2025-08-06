repeat 
	task.wait()
until game:IsLoaded() and game:GetService('Players') and game:GetService('Players').LocalPlayer and workspace

if game:GetService('CoreGui'):FindFirstChild("lnwza") then
	game:GetService('CoreGui'):FindFirstChild("lnwza"):Destroy()
end

local Configs, 
Connections, Nets,
Indexing ={
},{
},{
},{
}

local Utility: any? = (function()
	local _Index = {}

	function _Index:GetService(Injection: Service)
		local RE = game:GetService(Injection) do
			if cloneref then
				return cloneref(RE)
			end
			return RE
		end
	end

	function _Index:RE(Function: string)
		local FE = (getgenv()[Function] and clonefunction(getgenv()[Function])) or function(...) 
			return (...) end do
			return FE
		end
	end

	function _Index:Setup(Events: Controller, Touched: Mouse)
		self['9e9'] = function()
			Touched:CaptureController()
			Touched:ClickButton2(Vector2.new())
		end
		return (table.insert(Connections or {}, Events:Connect(self['9e9'])))
	end

	function _Index:Dictionary(keys: table, value: any, simple: boolean)
		local Dictionary = {}
		for _, k in pairs(keys) do
			Dictionary[k] = value
		end
		return (not simple and table.unpack(Dictionary)) or Dictionary
	end

	function _Index:SetCheck()
		for _,v in pairs(Indexing) do
			if Configs[v] == true then
				return true 
			end 
		end 
		return false 
	end

	return _Index
end)()

local Players: Players = Utility:GetService("Players")
local Lighting: Lighting = Utility:GetService('Lighting')
local TeleportService: TeleportService = Utility:GetService('TeleportService')
local VirtualUser: VirtualUser = Utility:GetService('VirtualUser')
local RunService: RunService = Utility:GetService('RunService')
local HttpService: HttpService = Utility:GetService('HttpService')
local UserInputService: UserInputService = Utility:GetService('UserInputService')

local LocalPlayer: LocalPlayer = Players.LocalPlayer

local translate = function(en: string, th: string)
	if Configs['Lauguage'] == "ไทย" then
		return tostring(th)
	end
	return tostring(en)
end

local Module = (function()
	local Cache = {
		['file'] = `dumper.gg/configs/{LocalPlayer.UserId}/{game.PlaceId}.json`,
		['isfolder'] = Utility:RE('isfolder'),
		['makefolder'] = Utility:RE('makefolder'),
		['writefile'] = Utility:RE('writefile'),
		['readfile'] = Utility:RE('readfile'),
		['isfile'] = Utility:RE('isfile')
	}

	Cache['Once'] = function(condition: any?, interval: number, fn: (() -> ())?, custom: (() -> boolean)?)
		while condition do
			local Tick = tick()
			if fn then fn() end
			if custom and custom() then break end
			repeat
				RunService.Heartbeat:Wait()
			until tick() - Tick >= (interval or 0.1)
		end
	end

	Cache['9e9'] = function(fn: () -> ())
		return task.spawn(function()
			while task.wait(0.1) do
				fn()
			end
		end)
	end

	Cache['Reversal'] = function(cursor: string?)
		local url = `https://games.roblox.com/v1/games/{game.PlaceId}/servers/Public?sortOrder=Asc&limit=100`
		if cursor then
			url ..= `&cursor={cursor}`
		end
		return HttpService:JSONDecode(game:HttpGet(url))
	end

	Cache['HOP'] = function()
		return task.spawn(function()
			local Server, Next
			repeat
				local Servers = Cache['Reversal'](Next)
				Server = Servers and Servers.data and Servers.data[1]
				Next = Servers and Servers.nextPageCursor
			until Server
			if not Server or not Server.id then return end
			return TeleportService:TeleportToPlaceInstance(game.PlaceId, Server.id, LocalPlayer)
		end)
	end

	Cache['Rejoin'] = function()
		if #Players:GetPlayers() <= 1 then
			LocalPlayer:Kick("\nRejoining")
			wait()
			return TeleportService:Teleport(game.PlaceId, LocalPlayer)
		end
		return TeleportService:TeleportToPlaceInstance(game.PlaceId, game.JobId, LocalPlayer)
	end

	Cache['html'] = function(text: string, color: Color3)
		if type(text) == "string" and typeof(color) == "Color3" then
			local r, g, b = math.floor(color.R * 255), math.floor(color.G * 255), math.floor(color.B * 255)
			return string.format('<font color="rgb(%d, %d, %d)">%s</font>', r, g, b, text)
		end
		return text
	end

	Cache['def'] = function(v: string, a: any?)
		if type(v) == "table" then
			for i, k in pairs(v) do
				if Configs[i] == nil then
					Configs[i] = k
				end
			end
			return
		end
		if Configs[v] == nil then
			Configs[v] = a
		end
	end

	Cache['save'] = function(key: string?, value: any?)
		local base = `dumper.gg/configs/{LocalPlayer.UserId}`
		local path = `{base}/{game.PlaceId}.json`

		if key ~= nil then
			Configs[key] = value
		end

		if not Cache.isfolder("dumper.gg") then
			Cache.makefolder("dumper.gg")
		end
		
		if not Cache.isfolder("dumper.gg/configs") then
			Cache.makefolder("dumper.gg/configs")
		end
		
		if not Cache.isfolder(base) then
			Cache.makefolder(base)
		end

		Cache.writefile(path, HttpService:JSONEncode(Configs))
	end

	Cache['load'] = function()
		local base = `dumper.gg/configs/{LocalPlayer.UserId}`
		local path = `{base}/{game.PlaceId}.json`

		if not Cache.isfolder("dumper.gg") then
			Cache.makefolder("dumper.gg")
		end
		
		if not Cache.isfolder("dumper.gg/configs") then
			Cache.makefolder("dumper.gg/configs")
		end
		
		if not Cache.isfolder(base) then
			Cache.makefolder(base)
		end

		if not Cache.isfile(path) then
			Cache.save()
		end

		return HttpService:JSONDecode(Cache.readfile(path))
	end

	Cache['tab'] = function(window: table ,title: string, desc: string, icon: number)
		return window:Add({
			Title = title,
			Desc = desc,
			Icon = icon
		}) 
	end

	Cache['sec'] = function(tab: table ,title: string, desc: string)
		return tab:Sec({
			Title = title,
			Side = desc
		}) 
	end

	Cache['button'] = function(sec: any, Title: string, Callback: any)
		return sec:Button({
			Title = Title,
			Callback = Callback
		}) 
	end

	Cache['list'] = function(sec: table, title: string, list: table, m: boolean, setting: string)
		sec:Dropdown({Title = title,Multi = m,List = list,Value = Configs[setting],Callback = function(v)
			Configs[setting] = v
			Cache.save(setting, v)
		end})
	end

	Cache['toggle'] = function(meta: table)
		local Section = meta.sec
		local Title = meta.title or "Toggle"
		local Index = meta.index or false
		local Setting = meta.setting or ""
		local Callback = meta.call
		local C
		if Index and Setting ~= "" then
			if not table.find(Indexing, Setting) then
				table.insert(Indexing, Setting)
			end
		end
		return Section:Toggle({
			Title = Title,
			Value = Configs[Setting],
			Callback = function(value)
				Configs[Setting] = value
				Cache.save(Setting, value)
				if value then
					C = task.spawn(function()
						if Nets[Setting] then
							Nets[Setting](Configs[Setting])
						end
					end)
				else
					if C then
						task.cancel(C)
					end
				end
				if typeof(Callback) == "function" then
					Callback(value)
				end
			end
		})
	end

	Cache['def']('X', 0)
	Cache['def']('Y', 0)

	Cache['init'] = function()
		if Configs['X'] == 0 and Configs['Y'] == 0 then
			if UserInputService.KeyboardEnabled then
				return UDim2.new(0, 750, 0, 800)
			else
				return UDim2.new(0, 500, 0, 350)
			end
		else
			return UDim2.new(0, Configs['X'], 0, Configs['Y'])
		end
	end

	function Cache:setup(window: table, queue: string)
		local Home = window:Add({Title = translate("Configure", "คอนฟิกเกอร์"),Desc = translate("Managers", "ระบบหลัก"),Icon = 132831270943713}) do
			local Performance = Home:Sec({Title = translate("Performance", "ประสิทธิภาพ"), Side = "r"}) do
				Cache.toggle({sec = Performance,title = translate("Enable White Screen", "เปิดใช้งานจอขาว"),setting = "White Screen",call = function(v)
					if not UserInputService.KeyboardEnabled then
						if v then
							RunService:Set3dRenderingEnabled(false)
						else
							RunService:Set3dRenderingEnabled(true)
						end
					end
				end})
				Cache['button'](Performance, translate('Boost FPS', "แก้แลค"), function()
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
			end

			local Server = Home:Sec({Title = translate("Server", "เซิร์ฟเวอร์"), Side = "r"}) do
				Cache.def('Input JobID', game.JobId)
				Server:Textbox({Value = Configs["Input JobID"], Callback = function(v)
					Configs["Input JobID"] = v
					Cache.save("Input JobID", v)
				end})
				Cache['button'](Server, translate("Join", "เข้าร่วม"), function()
					TeleportService:TeleportToPlaceInstance(game.PlaceId, Configs['Input JobID'], LocalPlayer)
				end)
				Cache['button'](Server, translate("Clipboard JobId", "คัดลอกไอดี"), function()
					pcall(setclipboard, game.JobId)
				end)
				Cache['button'](Server, translate("Rejoin", "รีจอยน์"), function()
					Cache['Rejoin']()
				end)
				Cache['button'](Server, translate("Change Server", "เปลี่ยนเซิร์ฟเวอร์"), function()
					Cache['HOP']()
				end)
			end

			local Config = Home:Sec({Title = translate("Configs", "การตั้งค่า"), Side = "l"}) do
				Cache.list(Config, translate("Language", 'เลือกภาษา'), {'ไทย', 'English [ Default ]'}, false, 'Lauguage')
				Cache['button'](Config, translate("Change Language", "เปลี่ยนภาษา"), function()
					Cache['Rejoin']()
				end)
				Config:Line()
				Cache['button'](Config, translate("Remove Configs [ Only This Game ]", "ลบการตั้งค่า [ เฉพาะแมพนี้ ]"), function()
					pcall(delfile, Cache.file)
				end)
				Cache['button'](Config, translate("Remove Configs [ All ]", "ลบการตั้งค่า [ ทุกแมพ ]"), function()
					pcall(delfolder, 'dumper.gg')
				end)
				Cache['button'](Config, translate("Break Auto Execute", "หยุดการรันอัตโนมัติทั้งหมด"), function()
					pcall(clearteleportqueue or clear_teleport_queue)
				end)
			end
		end

		pcall(queueonteleport, queue)
		Utility:Setup(LocalPlayer.Idled, VirtualUser)

		do repeat wait() until game:GetService("CoreGui").lnwza.Background
			game:GetService("CoreGui").lnwza.Background:GetPropertyChangedSignal("Size"):Connect(function()
				local size = game:GetService("CoreGui").lnwza.Background.Size
				Cache.save('X', size.X.Offset)
				Cache.save('Y', size.Y.Offset)
			end)
		end

		Cache['9e9'](function()
			pcall(function()
				if not UserInputService.KeyboardEnabled then return end
				if iswindowactive and iswindowactive() then
					RunService:Set3dRenderingEnabled(true)
				else
					RunService:Set3dRenderingEnabled(false)
				end
			end)
		end)

		return Home
	end

	Connections['Once'] = Cache['Once']
	Connections['9e9'] = Cache['9e9']
	Cache['Once'] = nil
	Cache['9e9'] = nil

	do
		if tostring(LocalPlayer.LocaleId) == "th-th" then
			Cache.def('Lauguage', 'ไทย')
		else
			Cache.def('Lauguage', 'English [ Default ]')
		end
	end

	Configs = Cache['load']()
	return Cache
end)()

return table.unpack({
	Utility,
	Configs,
	Connections,
	Nets,
	Module,
	translate
})
